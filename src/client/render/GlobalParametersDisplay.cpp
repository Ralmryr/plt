#include <iostream>
#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

GlobalParametersDisplay::GlobalParametersDisplay(){
    this->listComponents.push_back(make_unique<Image>(tempFrameImage));
    this->listComponents.push_back(make_unique<Image>(tempFillImage));
    this->listComponents.push_back(make_unique<Image>(tempLogoImage));
    this->listComponents.push_back(make_unique<Text>(tempMinText));
    this->listComponents.push_back(make_unique<Text>(tempMaxText));
    this->listComponents.push_back(make_unique<Text>(tempCurrentText));
    this->listComponents.push_back(make_unique<Image>(oxyFrameImage));
    this->listComponents.push_back(make_unique<Image>(oxyFillImage));
    this->listComponents.push_back(make_unique<Image>(oxyLogoImage));
    this->listComponents.push_back(make_unique<Text>((oxyMinText)));
    this->listComponents.push_back(make_unique<Text>(oxyMaxText));
    this->listComponents.push_back(make_unique<Text>(oxyCurrentText));
    this->listComponents.push_back(make_unique<Image>(oceanLogoImage));
    this->listComponents.push_back(make_unique<Text>(oceanCurrentText));
}

void GlobalParametersDisplay::update(unordered_map<string,string> data){

}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}

void GlobalParametersDisplay::setListComponents(const std::vector<std::unique_ptr<sf::Drawable>>& listComponents){}