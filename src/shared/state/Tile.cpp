//
// Created by cleme on 21/11/22.
//

#include "Tile.h"

using namespace std;
using namespace state;

Tile::Tile() {

}

Tile::~Tile() {

}

// [ { "x, y" : "type" } ]
std::pair<std::string, std::string> Tile::serializeUiData() const {
    pair<string, string> uiData;
    auto strCoords = to_string(coords.first) + "," + to_string(coords.second);
    uiData.insert({strData, to_string(type)});
    return uiData;
}


