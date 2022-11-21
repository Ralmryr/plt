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

std::unordered_map<std::string, std::string> Tile::serializeUiData() const {
    unordered_map<string, string> uiData;
    auto strData = to_string(coords.first) + "," + to_string(coords.second) + "," + to_string(type);
    uiData.insert({"Tile", strData});
    return uiData;
}


