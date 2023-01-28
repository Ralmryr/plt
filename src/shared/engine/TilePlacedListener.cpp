#include "TilePlacedListener.h"
#include <iostream>
#include <utility>

using namespace std;
using namespace engine;

TilePlacedListener::TilePlacedListener(const state::State &state, std::vector<std::shared_ptr<Reaction>> reactionList,
                                       EventDetails &eventDetails) : eventDetails(eventDetails), reactions(std::move(reactionList)){
    tileType = state::TileType(eventDetails["tileType"]);
}


engine::TilePlacedListener::~TilePlacedListener() = default;


// Returns the reactions if it is concerned by the event
std::vector<std::shared_ptr<Reaction>> TilePlacedListener::onNotify(EventManager &eventManager, EventDetails &eventDetails) {
    if (state::TileType(eventDetails["tileType"]) == tileType) {
        return reactions;
    }
    else {
        return {};
    }
}

