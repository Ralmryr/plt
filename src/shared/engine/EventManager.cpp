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
}

EventManager::~EventManager() {
    cout << "Event Manager destroyed" << endl;
}

// Adds a new permanent effect to a listener, typically a blue card effect
void EventManager::registerEvent(EventType eventType, shared_ptr<Event> event) {

}

void EventManager::notify(const StateEventDetails &eventDetails) {
    bool isActionValid = true;
    bool isOriginalEvent = false;

    // If the reactionQueue is empty, it means this call is the original one
    if(reactionQueue.isEmpty()) {
        isOriginalEvent = true;
    }

    EventType eventType = eventDetails.getEventType();
    auto newEvent = eventFactory[eventType](*state, eventDetails);
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
