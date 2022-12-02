//
// Created by cleme on 02/12/22.
//
#include "EventManager.h"
#include "TilePlacedEvent.h"

using namespace std;
using namespace engine;

EventManager::EventManager() : reactionQueue() {

}

EventManager::~EventManager() {

}

void EventManager::registerEvent(EventType eventType, std::shared_ptr<Event> event) {
    switch(eventType) {
        case CARD_PLAYED:
            cardPlayedListeners.push_back(std::move(event));
            break;
        case TILE_PLACED:
            tilePlacedListeners.push_back(std::move(event));
            break;
    }
}

void EventManager::notifyTilePlaced(state::TileType tileType, std::pair<int, int> position) {
    auto tilePlacedEvent = make_shared<TilePlacedEvent>(tileType, position, *state);
}

