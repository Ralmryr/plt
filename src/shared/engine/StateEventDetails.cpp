#include "StateEventDetails.h"

using namespace std;
using namespace engine;

StateEventDetails::StateEventDetails(EventType eventType) {
    this->eventType = eventType;
}

StateEventDetails::~StateEventDetails() {

}

StateEventDetails &StateEventDetails::setIdPlayer(int idPlayer) {
    this->idPlayer = idPlayer;
    return *this;
}

StateEventDetails &StateEventDetails::setIdCard(int idCard) {
    this->idCard = idCard;
    return *this;
}

StateEventDetails &StateEventDetails::setTilePosition(std::pair<int, int> position) {
    this->tilePosition = position;
    return *this;
}

StateEventDetails &StateEventDetails::setTileType(state::TileType tileType) {
    this->tileType = tileType;
    return *this;
}

int StateEventDetails::getIdPlayer() const {
    return this->idPlayer;
}

int StateEventDetails::getIdCard() const {
    return this->idCard;
}

std::pair<int, int> StateEventDetails::getTilePosition() const {
    return this->tilePosition;
}

state::TileType StateEventDetails::getTileType() const {
    return this->tileType;
}

EventType StateEventDetails::getEventType() const {
    return this->eventType;
}

