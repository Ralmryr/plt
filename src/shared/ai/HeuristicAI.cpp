//
// Created by arthur on 19/12/22.
//

#include "HeuristicAI.h"

using namespace ai;
using namespace std;

ai::HeuristicAI::HeuristicAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
}

ai::HeuristicAI::~HeuristicAI()= default;

void ai::HeuristicAI::playTurn() {}

int ai::HeuristicAI::chooseBestCard() {
    return 0;
}

std::pair<int, int> ai::HeuristicAI::findBestPosition(state::TileType tile) {
    std::pair<int, int> Coord;

    if(tile ==state::FOREST){
        //look for your cities on the board
        //return the coord adjacent to the most of your cities
    }

    else if(tile ==state::CITY  ){
        //look for any forest on the board
        //return the coord adjacent to the most forest
    }

    else if(tile ==state::CAPITAL){
        //look for any forest and ocean on the board
        //return the coord adjacent to the most forest and ocean (ocean priority)
    }

    else if(tile ==state::NOCTIS || tile ==state::GANYMEDE || tile ==state::PHOBOS){
        //place on reserved tile
    }

    else {
        //find best authorized placement bonus
    }
    return Coord;
}