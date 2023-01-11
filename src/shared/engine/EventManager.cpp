#include <iostream>
#include <utility>

#include "EventManager.h"
#include "BadgePlayedListener.h"
#include "TilePlacedListener.h"
#include "IncreaseGPReaction.h"
#include "ModifyResourceReaction.h"
#include "PlaceTileReaction.h"

using namespace std;
using namespace engine;



EventManager::EventManager() : reactionQueue(){
    cardReader = make_unique<CardReader>();
    isActionValid = true;

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
    // Stops an event to propagate if the previous action was invalid
    if(!isActionValid) return;

    bool isOriginalEvent = false;

    // If the reactionQueue is empty, it means this call is the original one
    if(reactionQueue.isEmpty()) {
        isOriginalEvent = true;
    }

    EventType eventType = eventDetails.getEventType();

    // Reacts to a card played
    if (eventType == CARD_PLAYED) {
        int idCard = eventDetails["idCardPlayed"];
        cardReader->parseCard(idCard, state);

        auto payReaction = cardReader->getPayReaction();
        processReactions(payReaction);

        auto instantReaction = cardReader->getInstantReactions();
        processReactions(instantReaction);

        // Once all effects are triggered, executes all the commands
        if(isActionValid) {
            reactionQueue.consume();
        }

        cardReader->clear();
        reactionQueue.clearAll();
        isActionValid = true;
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



}

// Checks if the reactions are allowed, and adds them to the list. It also creates the chain effects by activating notifications
void EventManager::processReactions(const vector<std::shared_ptr<Reaction>> &reactions) {
    if(!isActionValid) return;

    for(const auto& reaction : reactions) {
        isActionValid = reaction->query();
        if(!isActionValid) {
            cout << "Action not possible ! " << endl;
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

    auto addRes = make_shared<ModifyResourceReaction>(*state, 3, state::GOLD, 0);
    auto addRes2 = make_shared<ModifyResourceReaction>(*state, 5, state::IRON, 0);
    auto placeForest = make_shared<PlaceTileReaction>(*state, pair<int, int>(2, 1), state::TileType::FOREST, 0);
    vector<shared_ptr<Reaction>> addResVector = {addRes, addRes2, placeForest};
    auto addResEventDetails = EventDetails(TILE_PLACED);
    addResEventDetails["tileType"] = state::TileType::OCEAN;
    auto addResListener = make_shared<TilePlacedListener>(*state, addResVector, addResEventDetails);

    listenersMap[TILE_PLACED].push_back(addResListener);
}

/*
 *  Handles a notification :
 *      - Creates a new event based on the data received
 *      - Notifies all listeners of the action performed
 *      - Executes all actions if the request is valid, otherwise doesn't do anything
 *      - Registers permanent listeners

void EventManager::notify(const EventDetails &eventDetails) {
    // Stops an event to propagate if the previous action was invalid
    if(!isActionValid) return;

    bool isOriginalEvent = false;

    // If the reactionQueue is empty, it means this call is the original one
    if(reactionQueue.isEmpty()) {
        isOriginalEvent = true;
    }

    // Creates a new event of the right type based on the event details received
    EventType eventType = eventDetails.getEventType();
    auto newEvent = eventFactory[eventType](*state, eventDetails);
    // Trigger the event
    isActionValid = newEvent->onNotify(*this);

    // Notify everyone that was listening to this eventType
    for(const auto& event : listenersMap[eventType]) {
        if(!isActionValid) {
            cout << "Can't execute action" << endl;
            reactionQueue.clearAll();
            break;
        }
        event->onNotify(*this);
    }

    // If this is the original call and all actions are valid, the queue is executed
    if(isOriginalEvent) {
        if(isActionValid) {
            reactionQueue.consume();
            reactionQueue.clearAll();

            // If the event had a permanent effect
            if(newEvent->getIsPermanent()) {
                listenersMap[eventType].push_back(newEvent);
            }
        }
            // This case is when an action was invalid and this is the last call, so we reset the flag
        else {
            isActionValid = true;
        }
    }
} */
