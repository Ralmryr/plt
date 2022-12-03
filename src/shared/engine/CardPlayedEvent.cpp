#include "CardPlayedEvent.h"

#include <iostream>

using namespace std;
using namespace engine;

CardPlayedEvent::CardPlayedEvent(const state::State &state, const StateEventDetails& eventDetails) {
    cout << "Card played event constructed" << endl;
}

CardPlayedEvent::~CardPlayedEvent() {
    cout << "Card played event destructed" << endl;
}

bool CardPlayedEvent::onNotify(EventManager& eventManager) {
    return false;
}
