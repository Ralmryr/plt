
#include "TilePlacedEvent.h"

engine::TilePlacedEvent::TilePlacedEvent(state::TileType tileType, std::pair<int, int> position, const state::State &state) {

}

engine::TilePlacedEvent::~TilePlacedEvent() {

}

bool engine::TilePlacedEvent::onNotify(engine::EventManager &eventManager) {
    return false;
}

