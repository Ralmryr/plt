//
// Created by ismail on 04/10/22.
//

#include "OnRessource.h"

state::OnRessource::OnRessource(std::vector<Ressource *> ressource) : ressource(ressource){

}

state::OnRessource::~OnRessource() {
    for(auto res : ressource) {
        delete res;
    }
}

bool state::OnRessource::checkCondition(state::Tile tile, state::Spot spot) {
    return PlaceCondition::checkCondition(tile, spot);
}
