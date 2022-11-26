//
// Created by cleme on 21/11/22.
//

#include "Tile.h"

using namespace std;
using namespace state;

Tile::Tile() {

}

Tile::Tile(std::pair<int, int> coords, Type type) {
    this->coords = coords;
    this->type = type;
}

Tile::~Tile() {

}

// [ "x, y" : "type" ]
std::pair<std::string, std::string> Tile::serializeUiData() const {
    pair<string, string> uiData;
    auto strCoords = to_string(coords.first) + "," + to_string(coords.second);
    uiData = {strCoords, to_string(type)};
    return uiData;
}

// Here just to be able to store it in a map
bool Tile::operator()(const Tile &tileL, const Tile &tileR) const {
    return tileL.coords.first < tileR.coords.first && tileL.coords.second < tileR.coords.second;
}


