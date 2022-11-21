#include "StdProjectDisplay.h"
#include <iostream>

using namespace render;
using namespace std;

StdProjectDisplay::StdProjectDisplay() {
    //frameImage
    sf::Vector2f posFrameImage;
    posFrameImage.x=0;
    posFrameImage.y=0;
    this->frameImage = Image("../src/client/img/std_project_background",posFrameImage);
    listComponents.push_back(make_unique<Image>(frameImage));

    //discardButton
    sf::Vector2f posDiscardButton;
    posFrameImage.x=0;
    posFrameImage.y=0;
    ClickableArea clickAreaDiscardButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_discard", clickAreaDiscardButton,posDiscardButton);
    listComponents.push_back(make_unique<Button>(discardButton));

    //prodEnergyButton
    sf::Vector2f posProdEnergyButton;
    posProdEnergyButton.x=0;
    posProdEnergyButton.y=0;
    ClickableArea clickAreaProdEnergyButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_prod_energy", clickAreaProdEnergyButton,posProdEnergyButton);
    listComponents.push_back(make_unique<Button>(prodEnergyButton));

    //temperatureButton
    sf::Vector2f posTemperatureButton;
    posTemperatureButton.x=0;
    posTemperatureButton.y=0;
    ClickableArea clickAreaTemperatureButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_temperature", clickAreaTemperatureButton,posTemperatureButton);
    listComponents.push_back(make_unique<Button>(temperatureButton));

    //oceanButton
    sf::Vector2f posOceanButton;
    posOceanButton.x=0;
    posOceanButton.y=0;
    ClickableArea clickAreaOceanButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_ocean", clickAreaOceanButton,posOceanButton);
    listComponents.push_back(make_unique<Button>(oceanButton));

    //forestButton
    sf::Vector2f posForestButton;
    posForestButton.x=0;
    posForestButton.y=0;
    ClickableArea clickAreaForestButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_forest", clickAreaForestButton,posForestButton);
    listComponents.push_back(make_unique<Button>(forestButton));

    //cityButton
    sf::Vector2f posCityButton;
    posCityButton.x=0;
    posCityButton.y=0;
    ClickableArea clickAreaCityButton=ClickableArea();
    this->discardButton=Button("../src/client/img/std_project_city", clickAreaCityButton,posCityButton);
    listComponents.push_back(make_unique<Button>(cityButton));


}

StdProjectDisplay::~StdProjectDisplay() {}

void StdProjectDisplay::draw(sf::RenderWindow &window) {
    for(const auto &component : this->listComponents){
        window.draw(*component);
    }
}

void StdProjectDisplay::update() {
}
