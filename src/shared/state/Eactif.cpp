//
// Created by ismail on 04/10/22.
//

#include "Eactif.h"

state::Eactif::Eactif(state::Ressource* cost, state::Gain* gain, state::ProjectCard *card)
    : cost(cost), gain(gain), card(card) {

}

state::Eactif::~Eactif() {
    delete this->cost;
    delete this->gain;
    delete this->card;
}
