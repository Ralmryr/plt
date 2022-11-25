#include "Board.h"
#include <string>
#include <iostream>

using namespace std;
using namespace state;


Board::Board() {
    for(int i = -4; i < 5; i++){
        Tile newTile = Tile({i, i}, CITY);
        listTiles.push_back(newTile);
        listOwners.push_back(i);
    }
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
