#include <iostream>
#include "PlaceTileReaction.h"
#include "state/Tile.h"
#include "state/Board.h"

using namespace engine;
using namespace std;
using namespace state;

static int counter = 0;

PlaceTileReaction::PlaceTileReaction(const State& state, pair<int, int> coords, TileType tileType, int idPlayer){
    this->board = state.getBoard();
    this->coords = coords;
    this->tileType = tileType;
    this->idPlayer = idPlayer;
}

PlaceTileReaction::~PlaceTileReaction(){

}

void PlaceTileReaction::execute (){
    board->placeTile(coords,tileType,idPlayer);
}

bool PlaceTileReaction::query () {
    board->isPossibleToPlaceTile(coords,tileType);
    return true;
}

void PlaceTileReaction::procNotification (){
    board->procNotification(tileType);
}