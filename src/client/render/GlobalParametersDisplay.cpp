#include <iostream>
#include "../constants.hpp"
#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

GlobalParametersDisplay::GlobalParametersDisplay(){
    //Setting positions for components
    sf::Vector2f vtempFrame;
    sf::Vector2f vtempFill;
    sf::Vector2f vtempLogo;
    sf::Vector2f voxyFrame;
    sf::Vector2f voxyFill;
    sf::Vector2f voxyLogo;
    sf::Vector2f voceanLogo;
    sf::Vector2f vtempMin;
    sf::Vector2f vtempMax;
    sf::Vector2f vtempCurrent;
    sf::Vector2f voxyMin;
    sf::Vector2f voxyMax;
    sf::Vector2f voxyCurrent;
    sf::Vector2f voceanCurrent;


    //Initializing images
    tempFrameImage = make_shared<Image>(Image("tempFrameImage.png", vtempFrame));
    tempFillImage = make_shared<Image>(Image("tempFillImage.png", vtempFill));
    tempLogoImage = make_shared<Image>(Image("temperature.png", vtempLogo));
    oxyFrameImage = make_shared<Image>(Image("oxyFrameImage.png", voxyFrame));
    oxyFillImage = make_shared<Image>(Image("oxyFillImage.png", voxyFill));
    oxyLogoImage = make_shared<Image>(Image("oxygen.png", voxyLogo));
    oceanLogoImage = make_shared<Image>(Image("ocean.png", voceanLogo));

    //Initializing texts
    tempMinText = make_shared<Text>(Text(to_string(MIN_TEMPERATURE)+" °", vtempMin));
    tempMaxText = make_shared<Text>(Text(to_string(MAX_TEMPERATURE)+" °", vtempMax));
    tempCurrentText = make_shared<Text>(Text(to_string(STARTING_TEMPERATURE)+" °", vtempCurrent));
    oxyMinText = make_shared<Text>(Text(to_string(MIN_OXYGEN)+" %", voxyMin));
    oxyMaxText = make_shared<Text>(Text(to_string(MAX_OXYGEN)+" %", voxyMax));
    oxyCurrentText = make_shared<Text>(Text(to_string(STARTING_OXYGEN)+" %", voxyCurrent));
    oceanCurrentText = make_shared<Text>(Text(to_string(STARTING_OCEAN)+"/"+to_string(MAX_OCEAN), voceanCurrent));


    //Adding the components to the list
    this->listComponents.push_back(tempFrameImage);
    this->listComponents.push_back(tempFillImage);
    this->listComponents.push_back(tempLogoImage);
    this->listComponents.push_back(tempMinText);
    this->listComponents.push_back(tempMaxText);
    this->listComponents.push_back(tempCurrentText);
    this->listComponents.push_back(oxyFrameImage);
    this->listComponents.push_back(oxyFillImage);
    this->listComponents.push_back(oxyLogoImage);
    this->listComponents.push_back(oxyMinText);
    this->listComponents.push_back(oxyMaxText);
    this->listComponents.push_back(oxyCurrentText);
    this->listComponents.push_back(oceanLogoImage);
    this->listComponents.push_back(oceanCurrentText);
}

GlobalParametersDisplay::~GlobalParametersDisplay(){}

void GlobalParametersDisplay::update(unordered_map<string,string> data){
    //Getting current temperature oxygene and ocean datas
    int temp = stoi(data["Temperature"]);
    int oxy = stoi(data["Oxygene"]);

    //Setting new data texts
    tempCurrentText->setText(data["Temperature"] + " ° C");
    oxyCurrentText->setText(data["Oxygene"] + " %");
    oceanCurrentText->setText(data["Ocean"] + "/" + to_string(MAX_OCEAN));

    //Setting new sprite size for the fillers
    tempFillImage->setSize(sf::Vector2f(tempFillImage->getSize().x*temp, tempFillImage->getSize().y*temp));
    oxyFillImage->setSize(sf::Vector2f(oxyFillImage->getSize().x*oxy, oxyFillImage->getSize().y*oxy));

}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}