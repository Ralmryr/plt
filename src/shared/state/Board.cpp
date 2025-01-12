#include "Board.h"
#include <string>
#include <random>
#include <iostream>

using namespace std;
using namespace state;


Board::Board() {
//    for(int i = -4; i < 5; i++){
//        Tile newTile = Tile({i, i}, CITY);
//        listTiles.push_back(newTile);
//        listOwners.push_back(abs(i));
//    }

    int joe = 1;
    int mama = 4;
    for (int y = -4; y < 5; y++) {
        if(y<=0) joe--;
        if(y>0) mama--;
        for (int x = joe; x <= mama; x++) {
            // 1 chance out of 3 to generate a Tile
/*            if(rand()%3 == 0) continue;
            auto randTileType = rand()%3+1;
            auto randPlayer = rand()%5;
            Tile newTile = Tile({x, y}, TileType(randTileType));
            listTiles.push_back(newTile);
            listOwners.push_back(randPlayer);*/
        }
    }

    Tile newTile = Tile({-9, 5}, TileType(2));
    listTiles.push_back(newTile);
    listOwners.push_back(1);

    Tile new2Tile = Tile({-8, 2}, TileType(2));
    listTiles.push_back(new2Tile);
    listOwners.push_back(1);

    //Initialize reserved spot
    listReserved={
            //Don't modify, it will be incoherent
            {{-2,0},NOCTIS},
            {{-1,0},OCEAN},
            {{0,0},OCEAN},
            {{1,0},OCEAN},
            {{2,-1},OCEAN},
            {{3,-1},OCEAN},
            {{4,-1},OCEAN},
            {{4,-4},OCEAN},
            {{3,1},OCEAN},
            {{1,3},OCEAN},
            {{0,4},OCEAN},
            {{-2,4},OCEAN},
            {{-3,4},OCEAN},
            {{-9,5},PHOBOS},
            {{-8,2},GANYMEDE}
    };
}

Board::~Board() {

}

// Adds the data from every tile
// [ "x, y" : "type, idOwner" ]
unordered_map<string, string> Board::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(int i = 0; i < int(listOwners.size()); i++) {
        auto tileData = listTiles[i].serializeUiData();
        uiData.insert({tileData.first, tileData.second + "," + to_string(listOwners[i])});
    }
    return uiData;
}

vector<Tile> Board::getNeighbors (pair<int,int>currCoord){
    vector<Tile> neighbors;
    int currx=currCoord.first;
    int curry=currCoord.second;
    for(const auto& tile : listTiles){
        pair<int,int> coords=tile.getCoords();
        int x=coords.first;
        int y= coords.second;
        if(abs(currx-x)<=1 and abs(curry-y) and currx-x !=curry-y){
            neighbors.push_back(tile);
        }
    }
    return neighbors;
}

const std::vector<Tile> &Board::getListTiles() const {
    return listTiles;
}

const std::vector<int> &Board::getListOwners() const {
    return listOwners;
}

const std::map<std::pair<int, int>, TileType> &Board::getListReserved() const {
    return listReserved;
}

void Board::placeTile(std::pair<int, int> coords, state::TileType tileType, int idOwner) {
    Tile newTile=Tile(coords,tileType);
    listTiles.push_back(newTile);
    listOwners.push_back(idOwner);
}

bool Board::isPossibleToPlaceTile(std::pair<int, int> coords, state::TileType tileType) {
    pair<int, int> coordTile;

    for (const auto &tile: listTiles) {
        //Check if there is no tile on this coordinates
        coordTile = tile.getCoords();
        if (coords == coordTile) {
            return false;
        }
    }

    if (listReserved[coords]) {
        //Check if the spot is reserved
        if ((tileType == listReserved[coords]) || (tileType == MOHOL && listReserved[coords] == OCEAN)) {
            return true;
        } else return false;
    }

    //Others special conditions of placement
    if (tileType == CITY || tileType == CAPITAL) {
        //No adjacent city
        vector<Tile> neighborhood = getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == CITY || neighbor.getType() == NOCTIS || neighbor.getType() == CAPITAL) {
                return false;
            }
        }
        return true;
    } else if (tileType == PRESERVED) {
        //No adjacent tile
        vector<Tile> neighborhood = getNeighbors(coords);
        if (neighborhood.empty()) return true;
        else return false;
    } else if (tileType == INDUSTRY) {
        //Have to be adjacent to a city
        vector<Tile> neighborhood =getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == CITY || neighbor.getType() == NOCTIS || neighbor.getType() == CAPITAL) {
                return true;
            }
        }
        return false;
    } else if (tileType == ZOO) {
        //Have to be adjacent to a forest
        vector<Tile> neighborhood = getNeighbors(coords);
        for (const auto &neighbor: neighborhood) {
            if (neighbor.getType() == FOREST) {
                return true;
            }
        }
        return false;
    }else if(tileType==MINE){
        // TODO Need to be on a resource
        return true;
    }else return true;
}

void Board::procNotification(TileType tileType) {
    eventSender->notifyTilePlaced(tileType, {0, 0});
}

void Board::setEventSender(const shared_ptr<EventSender> &eventSender) {
    this->eventSender = eventSender;
}



