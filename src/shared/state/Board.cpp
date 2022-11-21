//
// Created by cleme on 21/11/22.
//

#include "Board.h"

using namespace std;
using namespace state;


Board::Board() {

}

Board::~Board() {

}

std::unordered_map<std::string, std::string> Board::serializeUiData() const {
    unordered_map<string, string> uiData;
    // Adds the data from every tile
    for(const auto& tile : listTiles) {
        auto mapTile = tile.first.serializeUiData();
        uiData.insert(mapTile.begin(), mapTile.end());
    }
    return uiData;
}
