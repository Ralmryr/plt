#include "BadgePlayedListener.h"

#include <iostream>

using namespace std;
using namespace engine;

BadgePlayedListener::BadgePlayedListener(const state::State &state, const EventDetails& eventDetails) {
    cout << "Card played event constructed" << endl;
}

BadgePlayedListener::~BadgePlayedListener() {
    cout << "Card played event destructed" << endl;
}

bool BadgePlayedListener::onNotify(EventManager& eventManager) {
    return false;
}
