#include <iostream>
#include "../constants.hpp"
#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

using vec2f = sf::Vector2f;
using vec2u = sf::Vector2u;

GlobalParametersDisplay::GlobalParametersDisplay(){

    subdivisionOxy = 38;
    subdivisionTemp = 14;

    vec2f baseCoords = {1500, 70};

    unsigned int frameWidth = 76;
    unsigned int frameHeight = 548;

    // Temperature bar
    vec2f vTempFrame = baseCoords + vec2f(100, 60);
    vec2f vTempLogo = {vTempFrame.x + 20, vTempFrame.y + frameHeight - 125};
    vec2u sTempFrame = {frameWidth, frameHeight};
    vec2u sTempLogo = {frameWidth - 40, 100};

    // Oxygen bar
    vec2f vOxyFrame = baseCoords + vec2f(240, 60);
    vec2f vOxyLogo = {vOxyFrame.x + 15, vOxyFrame.y + frameHeight - 90};
    vec2u sOxyFrame = {frameWidth, frameHeight};
    vec2u sOxyLogo = {frameWidth - 30, frameWidth - 30};

    // Ocean logo
    vec2f vOceanLogo = baseCoords + vec2f(140, 600);

    // Text
    vec2f vTempMin = {vTempFrame.x - 70, vTempFrame.y + frameHeight - 30};
    vec2f vTempMax = {vTempFrame.x - 55, vTempFrame.y};
    vec2f vTempCurrent = {vTempFrame.x + 10, vTempFrame.y + 30};
    vec2f vOxyMin = {vOxyFrame.x - 50, vOxyFrame.y + frameHeight - 30};
    vec2f vOxyMax = {vOxyFrame.x - 55, vOxyFrame.y};
    vec2f vOxyCurrent = {vOxyFrame.x + 15, vOxyFrame.y + 30};
    vec2f vOceanCurrent = {vOceanLogo.x + 30, vOceanLogo.y + 30};

    //Initializing image
    tempFrameImage = make_shared<Image>("frameTempOxy.png", vTempFrame, sTempFrame);
    tempFillImage = make_shared<Image>("tempFill.png", vec2f(0, 0));

    tempLogoImage = make_shared<Image>("temperature.png", vTempLogo, sTempLogo);
    oxyFrameImage = make_shared<Image>("frameTempOxy.png", vOxyFrame, sOxyFrame);
    oxyFillImage = make_shared<Image>("oxyFill.png", vec2f(0, 0));

    oxyLogoImage = make_shared<Image>("oxygen.png", vOxyLogo, sOxyLogo);
    oceanLogoImage = make_shared<Image>("ocean.png", vOceanLogo);
    oceanLogoImage->setScale(0.25f);

    //Initializing texts
    tempMinText = make_shared<Text>(to_string(MIN_TEMPERATURE) + " C", vTempMin);
    tempMaxText = make_shared<Text>(to_string(MAX_TEMPERATURE)+" C", vTempMax);
    tempCurrentText = make_shared<Text>(to_string(MIN_TEMPERATURE)+" C", vTempCurrent);
    oxyMinText = make_shared<Text>(to_string(MIN_OXYGEN)+" %", vOxyMin);
    oxyMaxText = make_shared<Text>(to_string(MAX_OXYGEN)+" %", vOxyMax);
    oxyCurrentText = make_shared<Text>(to_string(MIN_OXYGEN)+" %", vOxyCurrent);
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

void GlobalParametersDisplay::update(const unordered_map<string,string>& data){
    //Getting current temperature and oxygen
    int temp = stoi(data.at("Temperature"));
    int oxy = stoi(data.at("Oxygen"));

    //Setting new data texts
    tempCurrentText->setText(data.at("Temperature") + " C");
    oxyCurrentText->setText(data.at("Oxygen") + " %");
    oceanCurrentText->setText(data.at("NumberOceans")+ "/" + to_string(MAX_OCEAN));

    //Setting new sprite size for the fillers

    vec2f baseTempFill = {1608, 138};
    auto tempFillSize = tempFillImage->getSize();

    tempFillImage->setRect(sf::IntRect(0, abs(MAX_TEMPERATURE - temp)*subdivisionTemp, int(tempFillSize.x), (temp + 30) * subdivisionTemp));
    tempFillImage->setPosition(sf::Vector2f(baseTempFill.x, baseTempFill.y + abs(MAX_TEMPERATURE - temp)*subdivisionTemp));

    vec2f baseOxyFill = {1748, 138};
    auto oxyFillSize = oxyFillImage->getSize();

    oxyFillImage->setRect(sf::IntRect(0, (MAX_OXYGEN - oxy)*subdivisionOxy, int(oxyFillSize.x), oxy * subdivisionOxy));
    oxyFillImage->setPosition(sf::Vector2f(baseOxyFill.x, baseOxyFill.y + (MAX_OXYGEN - oxy)*subdivisionOxy));
}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}