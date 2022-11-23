#include "StdProjectDisplay.h"
#include <iostream>

using namespace render;
using namespace std;

StdProjectDisplay::StdProjectDisplay() {
    //frameImage
    sf::Vector2f posFrameImage = {0, 450};
    this->frameImage = make_shared<Image>("stdProjectFrameImage.png",posFrameImage);
    listComponents.push_back(frameImage);

    //discardButton
    sf::Vector2f posDiscardButton = {30, 460};
    ClickableArea clickAreaDiscardButton=ClickableArea();
    this->discardButton=make_shared<Button>("card.png", clickAreaDiscardButton,posDiscardButton);
    this->discardButton->setScale(0.1f);
    listComponents.push_back(discardButton);

    //prodEnergyButton
    sf::Vector2f posProdEnergyButton = {25, 525};
    ClickableArea clickAreaProdEnergyButton=ClickableArea();
    this->prodEnergyButton=make_shared<Button>("megacredit.png", clickAreaProdEnergyButton,posProdEnergyButton);
    this->prodEnergyButton->setScale(0.08f);
    listComponents.push_back(prodEnergyButton);

    //temperatureButton
    sf::Vector2f posTemperatureButton = {25, 585};
    ClickableArea clickAreaTemperatureButton=ClickableArea();
    this->temperatureButton=make_shared<Button>("megacredit.png", clickAreaTemperatureButton,posTemperatureButton);
    this->temperatureButton->setScale(0.08f);
    listComponents.push_back(temperatureButton);

    //oceanButton
    sf::Vector2f posOceanButton = {25, 645};
    ClickableArea clickAreaOceanButton=ClickableArea();
    this->oceanButton=make_shared<Button>("megacredit.png", clickAreaOceanButton,posOceanButton);
    this->oceanButton->setScale(0.08f);
    listComponents.push_back(oceanButton);

    //forestButton
    sf::Vector2f posForestButton = {25, 705};
    ClickableArea clickAreaForestButton=ClickableArea();
    this->forestButton= make_shared<Button>("megacredit.png", clickAreaForestButton,posForestButton);
    this->forestButton->setScale(0.08f);
    listComponents.push_back(forestButton);

    //cityButton
    sf::Vector2f posCityButton = {25, 765};
    ClickableArea clickAreaCityButton=ClickableArea();
    this->cityButton=make_shared<Button>("megacredit.png", clickAreaCityButton,posCityButton);
    this->cityButton->setScale(0.08f);
    listComponents.push_back(cityButton);


}

StdProjectDisplay::~StdProjectDisplay() {}

void StdProjectDisplay::draw(sf::RenderWindow &window) {
    for(const auto &component : this->listComponents){
        window.draw(*component);
    }
}

void StdProjectDisplay::update(std::unordered_map<std::string,std::string> data) {
}
