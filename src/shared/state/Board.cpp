//
// Created by ismail on 04/10/22.
//

#include "Board.h"

state::Board::Board() {
    int rangeInf = 0;
    int rangeSup = 4;
    // Creates a hexagon
    for(int y=-4; y <= 4; y++) {
        if(y <= 0) rangeInf--;
        if(y > 0) rangeSup--;
        for (int x = -rangeInf; x <= rangeSup; x++) {
            auto spot = Spot(x, y);
            this->emptyGrid.push_back(spot);
        }
    }
}

const std::vector<state::Spot> &state::Board::getEmptyGrid() const {
    return this->emptyGrid;
}

