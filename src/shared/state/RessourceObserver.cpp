//
// Created by cleme on 21/10/22.
//

#include "RessourceObserver.h"

state::RessourceObserver::RessourceObserver(state::Ressource *ressource) : ressourceToGain(ressource){

}

state::RessourceObserver::~RessourceObserver() {
    delete this->ressourceToGain;
}
