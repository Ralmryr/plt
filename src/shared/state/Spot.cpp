//
// Created by ismail on 04/10/22.
//

#include "Spot.h"

state::Spot::Spot(int, int) {
    this->x = x;
    this->y = y;
}

int state::Spot::getY() const {
    return this->y;
}

int state::Spot::getX() const {
    return this->x;
}

