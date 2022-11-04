//
// Created by cleme on 21/10/22.
//

#include "TileObserver.h"

state::TileObserver::TileObserver(state::Tile *tile) : toPlace(tile){

}

state::TileObserver::~TileObserver() {
    delete this->toPlace;
}
