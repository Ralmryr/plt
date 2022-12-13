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
    Tile newTile=Tile(coords,tileType);
    vector<Tile> listTiles;
    vector<int> listOwners;
    listTiles=board->getListTiles();
    listTiles.push_back(newTile);
    listOwners=board->getListOwners();
    listOwners.push_back(idPlayer);
}
bool PlaceTileReaction::query () {
    vector<Tile> listTiles;
    listTiles = board->getListTiles();
    map<pair<int, int>, TileType> listReserved = board->getListReserved();
    pair<int, int> coordTile;

    for (const auto &tile: listTiles) {
        //Check if there is no tile on this coordinates
        coordTile = tile.getCoords();
        if (this->coords == coordTile) {
            return false;
        }
    }

    if (listReserved[this->coords]) {
        //Check if the spot is reserved
        if ((tileType == listReserved[this->coords]) || (tileType == MOHOL && listReserved[this->coords] == OCEAN)) {
            return true;
        } else return false;
    }

    //Others special conditions of placement
    if (tileType == CITY || tileType == CAPITAL) {
        //No adjacent city
        vector<Tile> neighborhood = board->getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == CITY || neighbor.getType() == NOCTIS || neighbor.getType() == CAPITAL) {
                return false;
            }
        }
        return true;
    } else if (tileType == PRESERVED) {
        //No adjacent tile
        vector<Tile> neighborhood = board->getNeighbors(coords);
        if (neighborhood.empty()) return true;
        else return false;
    } else if (tileType == INDUSTRY) {
        //Have to be adjacent to a city
        vector<Tile> neighborhood = board->getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == CITY || neighbor.getType() == NOCTIS || neighbor.getType() == CAPITAL) {
                return true;
            }
        }
        return false;
    } else if (tileType == ZOO) {
        //Have to be adjacent to a forest
        vector<Tile> neighborhood = board->getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == FOREST) {
                return true;
            }
        }
        return false;
    }else if(tileType==MINE){
        //Need to be on a resource
        return true; // to implement
    }else return true;
}
void PlaceTileReaction::procNotification (){

}