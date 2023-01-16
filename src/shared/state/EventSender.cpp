#include "EventSender.h"

#include <iostream>
#include <utility>

using namespace std;
using namespace state;


EventSender::EventSender() {

}

EventSender::~EventSender() {

}

void EventSender::notifyCardPlayed(int idCard) {
    //eventManager->notifyCardPlayed(idCard);
}

void EventSender::notifyTilePlaced(TileType tileType, std::pair<int, int> position) {
    auto eventDetails = engine::EventDetails(engine::TILE_PLACED);
    eventDetails["tileType"] = tileType;
    eventManager->notify(eventDetails);
}

void EventSender::hookEventManager(std::shared_ptr<engine::EventManager> eventManager) {
    this->eventManager = std::move(eventManager);
}
