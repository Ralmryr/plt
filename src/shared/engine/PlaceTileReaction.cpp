#include "PlaceTileReaction.h"
#include "state/Tile.h"
#include "state/Board.h"

using namespace engine;
using namespace std;
using namespace state;

PlaceTileReaction::PlaceTileReaction(const state::State& state, std::pair<int, int> coords, state::TileType tileType, int idPlayer){
    std::shared_ptr<state::Board>  currentBoard=state.getBoard();
    this->board=currentBoard;
    this->coords=coords;
    this->tileType=tileType;
    this->idPlayer=idPlayer;
}

PlaceTileReaction::~PlaceTileReaction(){

}

void PlaceTileReaction::execute (){
    state::Tile newTile=Tile(coords,tileType);
    std::vector<Tile> listTiles;
    std::vector<int> listOwners;
    listTiles=board->getListTiles();
    listTiles.push_back(newTile);
    listOwners=board->getListOwners();
    listOwners.push_back(idPlayer);
}
bool PlaceTileReaction::query (){
    return true;
}
void PlaceTileReaction::procNotification (){

}