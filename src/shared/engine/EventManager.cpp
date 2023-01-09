#include <iostream>
#include <utility>
#include "EventManager.h"
#include "BadgePlayedListener.h"
#include "TilePlacedListener.h"

using namespace std;
using namespace engine;


// Helper function to populate the eventFactory
template<class T>
void addNewEvent(EventManager& eventManager, EventType eventType) {
    eventManager.getEventFactory()[eventType] = [] (const state::State& state, const EventDetails& eventDetails) {
        return make_shared<T>(state, eventDetails);
    };
}

EventManager::EventManager() : reactionQueue(){
    cardReader = make_unique<CardReader>();
    // Adds the types to the factory to easily create new Events
    addNewEvent<BadgePlayedListener>(*this, CARD_PLAYED);
    addNewEvent<TilePlacedListener>(*this, TILE_PLACED);
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
        reactionQueue.consume();
        cardReader->clear();
    }

    
}

ReactionQueue &EventManager::getReactionQueue() {
    return reactionQueue;
}

std::map<EventType, std::function<std::shared_ptr<Listener>(const state::State &, const EventDetails &eventDetails)>>&
EventManager::getEventFactory() {
    return this->eventFactory;
}

void EventManager::hookState(std::shared_ptr<state::State> state) {
    this->state = std::move(state);
}

// Checks if the reactions are allowed, and adds them to the list. It also creates the chain effects
void EventManager::processReactions(const vector<std::shared_ptr<Reaction>> &reactions) {
    for(const auto& reaction : reactions) {
        isActionValid = reaction->query();
        if(!isActionValid) {
            cout << "Action not possible ! " << endl;
            reactionQueue.clearAll();
            break;
        }
        reaction->procNotification();
        reactionQueue.addReaction(reaction);
    }
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
