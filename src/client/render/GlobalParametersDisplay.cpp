#include <iostream>
#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

GlobalParametersDisplay::GlobalParametersDisplay(){
    this->listComponents.push_back(make_unique(tempFrameImage));
    this->listComponents.push_back(make_unique(tempFillImage));
    this->listComponents.push_back(make_unique(tempLogoImage));
    this->listComponents.push_back(make_unique(tempMinText));
    this->listComponents.push_back(make_unique(tempMaxText));
    this->listComponents.push_back(make_unique(tempCurrentText));
    this->listComponents.push_back(make_unique(oxyFrameImage));
    this->listComponents.push_back(make_unique(oxyFillImage));
    this->listComponents.push_back(make_unique(oxyLogoImage));
    this->listComponents.push_back(make_unique(oxyMinText));
    this->listComponents.push_back(make_unique(oxyMaxText));
    this->listComponents.push_back(make_unique(oxyCurrentText));
    this->listComponents.push_back(make_unique(oceanLogoImage));
    this->listComponents.push_back(make_unique(oceanCurrentText));
}

void GlobalParametersDisplay::update(){

}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}

void GlobalParametersDisplay::setListComponents(const std::vector<std::unique_ptr<sf::Drawable>>& listComponents){}