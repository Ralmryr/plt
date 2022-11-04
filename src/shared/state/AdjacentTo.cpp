//
// Created by ismail on 04/10/22.
//

#include "AdjacentTo.h"

state::AdjacentTo::AdjacentTo(bool adjacent, state::Tile* tile) : adjacentTo(adjacent), tile(tile){

}

bool state::AdjacentTo::checkCondition(state::Tile tile, state::Spot spot) {
    return PlaceCondition::checkCondition(tile, spot);
}

state::AdjacentTo::~AdjacentTo() {
    delete this->tile;
};
