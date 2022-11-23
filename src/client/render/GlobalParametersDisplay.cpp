#include <iostream>
#include "../constants.hpp"
#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

using vec2f = sf::Vector2f;
using vec2u = sf::Vector2u;

GlobalParametersDisplay::GlobalParametersDisplay(){

    subdivisionOxy = 35;
    subdivisionTemp = 13;

    int currentTemp = 24;
    int currentOxy = 6;

    vec2f baseCoords = {1500, 70};

    unsigned int frameWidth = 60;
    unsigned int frameHeight = 548;
    // Temperature bar
    vec2f vTempFrame = baseCoords + vec2f(100, 60);
    vec2f vTempFill = {vTempFrame.x + 8, vTempFrame.y + 6 + (MAX_TEMPERATURE + 30 - currentTemp) * subdivisionTemp};
    //vTempFill = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
    vec2f vTempLogo = {vTempFrame.x + 10, vTempFrame.y + frameHeight - 125};
    vec2u sTempFrame = {frameWidth, frameHeight};
    vec2u sTempFill = {frameWidth - 16, frameHeight - 16};
    vec2u sTempLogo = {frameWidth - 24, 100};

    // Oxygen bar
    vec2f vOxyFrame = baseCoords + vec2f(240, 60);
    vec2f vOxyFill = {vOxyFrame.x + 8, vOxyFrame.y + 9 + (MAX_OXYGEN - currentOxy) * subdivisionOxy};
    vec2f vOxyLogo = {vOxyFrame.x + 5, vOxyFrame.y + frameHeight - 100};
    vec2u sOxyFrame = {frameWidth, frameHeight};
    vec2u sOxyFill = {frameWidth - 16, frameHeight - 16};
    vec2u sOxyLogo = {frameWidth - 10, frameWidth - 10};

    vec2f vOceanLogo = baseCoords + vec2f(140, 600);

    // Text
    vec2f vTempMin = {vTempFrame.x - 70, vTempFrame.y + frameHeight - 30};
    vec2f vTempMax = {vTempFrame.x - 55, vTempFrame.y};
    vec2f vTempCurrent = {vTempFrame.x, vTempFrame.y + 30};
    vec2f vOxyMin = {vOxyFrame.x - 50, vOxyFrame.y + frameHeight - 30};
    vec2f vOxyMax = {vOxyFrame.x - 55, vOxyFrame.y};
    vec2f vOxyCurrent = {vOxyFrame.x + 10, vOxyFrame.y + 30};
    vec2f vOceanCurrent = {vOceanLogo.x + 30, vOceanLogo.y + 30};

    //Initializing image
    tempFrameImage = make_shared<Image>("frameTempOxy.png", vTempFrame, sTempFrame);
    tempFillImage = make_shared<Image>("tempFill.png", vTempFill);

    tempFillImage->setRect(sf::IntRect(0, (MAX_TEMPERATURE-currentTemp+30)*subdivisionTemp, sTempFill.x, currentTemp * subdivisionTemp));

    tempLogoImage = make_shared<Image>("temperatur.png", vTempLogo, sTempLogo);
    oxyFrameImage = make_shared<Image>("frameTempOxy.png", vOxyFrame, sOxyFrame);
    oxyFillImage = make_shared<Image>("oxyFill.png", vOxyFill);

    oxyFillImage->setRect(sf::IntRect(0, (MAX_OXYGEN-currentOxy)*subdivisionOxy, sOxyFill.x, currentOxy * subdivisionOxy));

    oxyLogoImage = make_shared<Image>("oxygen.png", vOxyLogo, sOxyLogo);
    oceanLogoImage = make_shared<Image>("ocean.png", vOceanLogo);
    oceanLogoImage->setScale(0.25f);

    //Initializing texts
    tempMinText = make_shared<Text>(to_string(MIN_TEMPERATURE) + " C", vTempMin);
    tempMaxText = make_shared<Text>(to_string(MAX_TEMPERATURE)+" C", vTempMax);
    tempCurrentText = make_shared<Text>(to_string(currentTemp-30)+" C", vTempCurrent);
    oxyMinText = make_shared<Text>(to_string(MIN_OXYGEN)+" %", vOxyMin);
    oxyMaxText = make_shared<Text>(to_string(MAX_OXYGEN)+" %", vOxyMax);
    oxyCurrentText = make_shared<Text>(to_string(currentOxy)+" %", vOxyCurrent);
    oceanCurrentText = make_shared<Text>(to_string(STARTING_OCEAN)+"/"+to_string(MAX_OCEAN), vOceanCurrent);

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
    /*int temp = stoi(data["Temperature"]);
    int oxy = stoi(data["Oxygene"]);*/

    //Setting new data texts
    tempCurrentText->setText(data["Temperature"] + " ° C");
    oxyCurrentText->setText(data["Oxygene"] + " %");
    oceanCurrentText->setText(data["Ocean"] + "/" + to_string(MAX_OCEAN));

    //Setting new sprite size for the fillers
    /*tempFillImage->setSize(sf::Vector2f(tempFillImage->getSize().x*temp, tempFillImage->getSize().y*temp));
    oxyFillImage->setSize(sf::Vector2f(oxyFillImage->getSize().x*oxy, oxyFillImage->getSize().y*oxy));*/
}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}