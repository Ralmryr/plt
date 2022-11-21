#include <iostream>
#include "ClickableArea.h"

using namespace render;
using namespace std;

ClickableArea::ClickableArea() {

}

ClickableArea::~ClickableArea() {}

void ClickableArea::onClick(){
    //Call callback function
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
}
