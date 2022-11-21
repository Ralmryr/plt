#include <iostream>
#include "Popup.h"

using namespace render;
using namespace std;

Popup::Popup() {
    this->listComponents.push_back(make_unique<Image>(frameImage));
    this->listComponents.push_back(make_unique<Button>(closeButton));
}

Popup::~Popup(){}

void Popup::open(){
    this->isOpen = true;
}

void Popup::close(){
    this->isOpen = false;
}

void Popup::draw(sf::RenderWindow& window){
    if(isOpen) { // if the popup is open we draw all the components
        for(const auto &component : this->listComponents){
            window.draw(*component);
        }
    }

}

void Popup::setListComponents(const std::vector<std::unique_ptr<UiComponent>>& listComponents){

}