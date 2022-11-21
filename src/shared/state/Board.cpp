//
// Created by cleme on 21/11/22.
//

#include "Board.h"

using namespace std;
using namespace state;


Board::Board() {
    int joe = 0;
    int mama = 0;
    for(int y = -4; i < 5; i++) {
        if( y <= 0) joe--;
        if( y > 0) mama--;
        for(int x = joe; x < mama; x++) {
            listTiles.insert()
        }
    }
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
