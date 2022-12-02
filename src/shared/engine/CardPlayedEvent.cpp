#include "CardPlayedEvent.h"

using namespace std;
using namespace engine;

CardPlayedEvent::CardPlayedEvent(int idCard, int idPlayer, const state::State &state) {

}

CardPlayedEvent::~CardPlayedEvent() {

}

bool CardPlayedEvent::onNotify(EventManager& eventManager) {
    return false;
}
