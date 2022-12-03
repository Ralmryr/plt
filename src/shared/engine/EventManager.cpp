#include <iostream>
#include "EventManager.h"
#include "TilePlacedEvent.h"
#include "CardPlayedEvent.h"

using namespace std;
using namespace engine;


// Helper function to populate the eventFactory
template<class T>
void addNewEvent(EventManager& eventManager, EventType eventType) {
    eventManager.getEventFactory()[eventType] = [] (const state::State& state, const StateEventDetails& eventDetails) {
        return make_shared<T>(state, eventDetails);
    };
}

EventManager::EventManager() : reactionQueue() {
    // Adds the types to the factory to easily create new Events
    addNewEvent<CardPlayedEvent>(*this, CARD_PLAYED);
    addNewEvent<TilePlacedEvent>(*this, TILE_PLACED);

    isActionValid = true;
}

EventManager::~EventManager() {
    cout << "Event Manager destroyed" << endl;
}

// Adds a new permanent effect to a listener, typically a blue card effect
void EventManager::registerEvent(EventType eventType, shared_ptr<Event> event) {

}

/*
 *  Handles a notification :
 *      - Creates a new event based on the data received
 *      - Notifies all listeners of the action performed
 *      - Executes all actions if the request is valid, otherwise doesn't do anything
 *      - Registers permanent listeners
 */
void EventManager::notify(const StateEventDetails &eventDetails) {
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
    newEvent->setIsPermanent(true);
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
}

ReactionQueue &EventManager::getReactionQueue() {
    return reactionQueue;
}

std::map<EventType, std::function<std::shared_ptr<Event>(const state::State &, const StateEventDetails &eventDetails)>>&
EventManager::getEventFactory() {
    return this->eventFactory;
}

void EventManager::hookState(std::shared_ptr<state::State> state) {
    this->state = state;
}

/*
void EventManager::notifyTilePlaced(state::TileType tileType, std::pair<int, int> position) {

    // We create the event to notify it afterwards
    auto tilePlacedEvent = make_shared<TilePlacedEvent>(tileType, position, *state);
    isActionValid = tilePlacedEvent->onNotify(*this);

    // We notify the other events that might be interested in the current event
    for(const auto& event : tilePlacedListeners) {
        if(!isActionValid) {
            reactionQueue.clearAll();
            cout << "Unable to execute action" << endl;
            break;
        }
        isActionValid = event->onNotify(*this);
    }

    // If this is the original call, it means that the chain reaction has finished
    if(isOriginalEvent) {
        reactionQueue.consume();
    }
}

void EventManager::notifyCardPlayed(int idCard) {
    bool isActionValid = true;
    // We create the event to notify it afterwards
    auto cardPlayedEvent = make_shared<CardPlayedEvent>(idCard, 0, *state);
    isActionValid = cardPlayedEvent->onNotify(*this);

    // We notify the other events that might be interested in the current event
    for (const auto &event: cardPlayedListeners) {
        if(!isActionValid) {
            reactionQueue.clearAll();
            cout << "Unable to execute action" << endl;
            break;
        }
        isActionValid = event->onNotify(*this);
    }
}*/
