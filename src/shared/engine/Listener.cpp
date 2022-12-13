//
// Created by cleme on 02/12/22.
//
#include "Listener.h"

engine::Listener::Listener() {

}

engine::Listener::~Listener() {

}

bool engine::Event::getIsPermanent() const {
    return isPermanent;
}

void engine::Event::setIsPermanent(bool isPermanent) {
    this->isPermanent = isPermanent;
}

