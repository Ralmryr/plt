#include <iostream>
#include <utility>

#include "EventManager.h"
#include "BadgePlayedListener.h"
#include "TilePlacedListener.h"
#include "IncreaseGPReaction.h"

using namespace std;
using namespace engine;



EventManager::EventManager() : reactionQueue(){
    cardReader = make_unique<CardReader>();
    errorMessage = "";

}

EventManager::~EventManager() {
    cout << "Event Manager destroyed" << endl;
}

// Adds a new permanent effect to a listener, typically a blue card effect
void EventManager::registerEvent(EventType eventType, shared_ptr<Listener> event) {

}

/*
 *  Handles a notification :
 *      - Creates a new event based on the data received
 *      - Notifies all listeners of the action performed
 *      - Executes all actions if the request is valid, otherwise doesn't do anything
 *      - Registers permanent listeners
 */
void EventManager::notify(EventDetails &eventDetails) {
    // Stops an event to propagate if an action has led to an error message
    if(!errorMessage.empty()) return;

    EventType eventType = eventDetails.getEventType();

    // Reacts to a card played
    if (eventType == CARD_PLAYED) {
        int idCard = eventDetails["idCardPlayed"];
        cout << "Card played : " << idCard << endl;
        cardReader->parseCardEffects(idCard, state);

        auto payReaction = cardReader->getPayReaction();
        processReactions(payReaction);

        auto instantReaction = cardReader->getInstantReactions();
        processReactions(instantReaction);

        // Once all effects are triggered, executes all the commands
        if(errorMessage.empty()) {
            reactionQueue.consume();
            state->increaseActionCount();
        }

        cardReader->clear();
        reactionQueue.clearAll();
        errorMessage = "";
    }

    // Then it will iterate over the different event types to see if there is any listener that is interested in the event
    if(eventType != CARD_PLAYED) {
        vector<shared_ptr<Reaction>> reactions;
        for (const auto &listener: listenersMap[eventType]) {
            auto tmpReactions = listener->onNotify(*this, eventDetails);
            reactions.insert(reactions.end(), tmpReactions.begin(), tmpReactions.end());
        }

        processReactions(reactions);
    }

    //Forcing end turn
    if(eventType == FORCE_END_TURN){
        state->forceEndTurn();
    }
}

// Checks if the reactions are allowed, and adds them to the list. It also creates the chain effects by activating notifications
void EventManager::processReactions(const vector<std::shared_ptr<Reaction>> &reactions) {
    if(!errorMessage.empty()) return;

    for(const auto& reaction : reactions) {
        errorMessage = reaction->query();
        if(!errorMessage.empty()) {
            cout << errorMessage << endl;
            break;
        }
        reaction->procNotification();
        reactionQueue.addReaction(reaction);
    }
}

void EventManager::hookState(std::shared_ptr<state::State> state) {
    this->state = std::move(state);
}

void EventManager::initPermanentReactions() {
    auto increaseOxygenReaction = make_shared<IncreaseGPReaction>(*state, 1, "oxygen");
    vector<shared_ptr<Reaction>> reactionVector = {increaseOxygenReaction};
    auto forestPlacedEventDetails = EventDetails(TILE_PLACED);
    forestPlacedEventDetails["tileType"] = state::TileType::FOREST;
    auto forestPlacedListener = make_shared<TilePlacedListener>(*state, reactionVector,
                                                                forestPlacedEventDetails);
    listenersMap[TILE_PLACED].push_back(forestPlacedListener);
}

std::string EventManager::getErrorMessage() {
    return errorMessage;
}
