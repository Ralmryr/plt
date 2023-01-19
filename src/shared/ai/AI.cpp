
#include "AI.h"

using namespace ai;
using namespace std;


void ai::AI::passTurn() {
    //call a forcce end turn event in the eventManager
    engine::EventDetails eventDetails(engine::FORCE_END_TURN);
    manager->notify(eventDetails);
}


//tile placement methods and algorithms
std::pair<int, int> AI::findBestPosition(state::TileType tile) {
    return {};
}


int AI::chooseBestCard() {
    return 0;
}

void AI::playTurn() {

}
