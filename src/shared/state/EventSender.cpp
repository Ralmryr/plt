#include "EventSender.h"

#include <iostream>

using namespace std;
using namespace state;


EventSender::EventSender() {
    cout <<"Event sender constructed" << endl;
}

EventSender::~EventSender() {

}

void EventSender::notifyCardPlayed(int idCard) {
    //eventManager->notifyCardPlayed(idCard);
}

void EventSender::notifyTilePlaced(TileType tileType, std::pair<int, int> position) {
    //eventManager->notifyTilePlaced(tileType, position);
}

void EventSender::hookEventManager(std::shared_ptr<engine::EventManager> eventManager) {
    this->eventManager = eventManager;
}
