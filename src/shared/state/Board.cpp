//
// Created by cleme on 21/11/22.
//

#include "Board.h"
#include <string>

using namespace std;
using namespace state;


Board::Board() {

}

Board::~Board() {

}

std::unordered_map<std::string, std::string> Board::serializeUiData() const {
    unordered_map<string, string> uiData;
    // Adds the data from every tile
    // [ {x, y} : {type, idOwner} ]
    for(const auto& tile : listTiles) {
        auto pairTile = tile.first.serializeUiData();
        auto strData = pairTile.second + "," + to_string(tile.second);
        uiData.insert({pairTile.first, strData});
    }
    return uiData;
}
