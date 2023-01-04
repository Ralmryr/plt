#include "PlaceTileReaction.h"
#include "state/Tile.h"
#include "state/Board.h"

using namespace engine;
using namespace std;
using namespace state;

PlaceTileReaction::PlaceTileReaction(const State& state, pair<int, int> coords, TileType tileType, int idPlayer){
    shared_ptr<Board>  currentBoard=state.getBoard();
    this->board=currentBoard;
    this->coords=coords;
    this->tileType=tileType;
    this->idPlayer=idPlayer;
}

PlaceTileReaction::~PlaceTileReaction(){

}

void PlaceTileReaction::execute (){
    board->placeTile(coords,tileType,idPlayer);
}

bool PlaceTileReaction::query () {
    board->isPossibleToPlaceTile(coords,tileType);
}
void PlaceTileReaction::procNotification (){

}