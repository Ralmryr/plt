#include "Board.h"
#include <string>
#include <random>

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
            auto randTileType = rand()%3+1;
            auto randPlayer = rand()%5;
            Tile newTile = Tile({x, y}, Type(randTileType));
            listTiles.push_back(newTile);
            listOwners.push_back(randPlayer);
        }
    }

    Tile newTile = Tile({-9, 5}, Type(2));
    listTiles.push_back(newTile);
    listOwners.push_back(1);

    Tile new2Tile = Tile({-8, 2}, Type(2));
    listTiles.push_back(new2Tile);
    listOwners.push_back(1);
}

Board::~Board() {

}

// Adds the data from every tile
// [ "x, y" : "type, idOwner" ]
std::unordered_map<std::string, std::string> Board::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(int i = 0; i < int(listOwners.size()); i++) {
        auto tileData = listTiles[i].serializeUiData();
        uiData.insert({tileData.first, tileData.second + "," + to_string(listOwners[i])});
    }
    return uiData;
}
