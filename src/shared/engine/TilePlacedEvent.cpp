#include "TilePlacedListener.h"
#include <iostream>

using namespace std;
using namespace engine;


engine::TilePlacedListener::TilePlacedListener(const state::State &state, const EventDetails& eventDetails) {
    cout << "Tile placed event constructed" << endl;
}

engine::TilePlacedListener::~TilePlacedListener() {
    cout << "Tile placed event destructed" << endl;
}

bool engine::TilePlacedListener::onNotify(engine::EventManager &eventManager) {
    return false;
}

