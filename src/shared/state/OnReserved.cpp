//
// Created by cleme on 21/10/22.
//

#include "OnReserved.h"

state::OnReserved::OnReserved(bool ocean) : ocean(ocean){

}

state::OnReserved::~OnReserved() {

}

bool state::OnReserved::checkCondition(state::Tile tile, state::Spot spot) {
    return PlaceCondition::checkCondition(tile, spot);
}
