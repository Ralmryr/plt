#include "TilePlacedEvent.h"
#include <iostream>

using namespace std;
using namespace engine;


engine::TilePlacedEvent::TilePlacedEvent(const state::State &state, const StateEventDetails& eventDetails) {
    cout << "Tile placed event constructed" << endl;
}

engine::TilePlacedEvent::~TilePlacedEvent() {
    cout << "Tile placed event destructed" << endl;
}

bool engine::TilePlacedEvent::onNotify(engine::EventManager &eventManager) {
    return false;
}

