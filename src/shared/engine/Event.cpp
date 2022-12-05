//
// Created by cleme on 02/12/22.
//
#include "Event.h"

engine::Event::Event() {

}

engine::Event::~Event() {

}

bool engine::Event::getIsPermanent() const {
    return isPermanent;
}

void engine::Event::setIsPermanent(bool isPermanent) {
    this->isPermanent = isPermanent;
}

