#include <iostream>
#include "ClickableArea.h"

using namespace render;
using namespace std;

ClickableArea::ClickableArea() {

}

ClickableArea::~ClickableArea() {}

void ClickableArea::onClick(){
    this->callback();
}

void ClickableArea::setPosition(const sf::Vector2f& position){
    this->position = position;
}

void ClickableArea::setSize(const sf::Vector2f& size){
    this->size = size;
}

void ClickableArea::setCallback(const function<void()>& callback){
    this->callback = callback;
<<<<<<< HEAD
}
=======
}
>>>>>>> 71918308e09dafee78746f5e79d4d278e21716cc
