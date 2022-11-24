#include "Board.h"
#include <string>

using namespace std;
using namespace state;


Board::Board() {
    for(int i = 0; i < 4; i++){
        Tile newTile = Tile({i, i}, OCEAN);
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
    for(int i = 0; i < listOwners.size(); i++) {
        auto tileData = listTiles[i].serializeUiData();
        uiData.insert({tileData.first, tileData.second + to_string(listOwners[i])});
    }
    return uiData;
}
