
#include "MenuDisplay.h"
#include <iostream>
#include "../constants.hpp"

using namespace render;
using namespace std;



MenuDisplay :: MenuDisplay (){

    //define positions for all button and image in the menu
    sf::Vector2f vframe = {-10, 850};
    sf::Vector2f vCard = {900, 810};
    sf::Vector2f vBlueCard = {1225, 870};
    sf::Vector2f vBadge = {1475, 900};

    //define the size of all sprites
    sf::Vector2u sizeBlueCardButton = {150, 200};

    //define all texts positions

    sf::Vector2f posBadgeText;
    sf::Vector2f posPVText = {1765, 905};


    //define Images

    this->frameImage = make_shared<Image>("menuFrame.png",vframe);

    //define buttons
    this->cardButton = make_shared<Button>("card.png",vCard);
    this->cardButton->setScale(0.55f);
    this->cardButton->updateClickableArea();
    this->cardButton->setFunctionStr("Open Cards Hand");


    this->blueCardButton = make_shared<Button>("blueCardsbutton.png",vBlueCard);
    this->blueCardButton->setSize(sizeBlueCardButton);
    this->blueCardButton->updateClickableArea();
    this->blueCardButton->setFunctionStr("Open Cards Blue");


    this->badgeButton = make_shared<Button>("badge_wild.png",vBadge);
    this->badgeButton->setScale(1.2f);
    this->badgeButton->updateClickableArea();
    this->badgeButton->setFunctionStr("Open Badge Popup");

    //define all texts

    this->badgeText = make_shared<Text>("Badges",posBadgeText);
    this->pvText = make_shared<Text>("0",posPVText);
    this->pvText->setSizeText(80);
    this->pvText->setColor(sf::Color::Black);

    listComponents.push_back(frameImage);
    listComponents.push_back(cardButton);
    listComponents.push_back(blueCardButton);
    listComponents.push_back(badgeButton);
    listComponents.push_back(pvText);

    // Initialize production of resources texts
    for(int i = 0; i < 6; i++){
        float posX = 150.0f + float(i) * 127.0f;
        sf::Vector2f textPos = {posX, 915};
        listResourceProd.push_back(make_shared<Text>("100", textPos));
        listComponents.push_back(listResourceProd.back());
    }
    // Initialize amount of resources texts
    for(int i = 0; i < 6; i++){
        float posX = 150.0f + float(i) * 127.0f;
        sf::Vector2f textPos = {posX, 1000};
        listResourceAmount.push_back(make_shared<Text>("100", textPos));
        listComponents.push_back(listResourceAmount.back());
    }

    listButtons.push_back(cardButton);
    listButtons.push_back(blueCardButton);
    listButtons.push_back(badgeButton);
}

MenuDisplay::~MenuDisplay() = default;

void MenuDisplay::update(const std::unordered_map<std::string,std::string>& data) {
    //update resources texts and pvtext

    for (const auto &dataEl: data) {
        if(dataEl.first == "PV") continue;
        // Gets the index in the Resource enum of the current resource that is processed
        auto resIndex = stoi(dataEl.first.substr(dataEl.first.find(" ")+1));
        // It is a production if the index is even
        if(resIndex % 2 == 0) {
            listResourceProd[(resIndex - 2) / 2]->setText(dataEl.second);
        }
        // Else it is an amount of resource
        else {
            listResourceAmount[(resIndex - 1)/2]->setText(dataEl.second);
        }
    }

    pvText->setText(data.at("PV"));
}

void MenuDisplay::draw (sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }

}

std::vector<std::shared_ptr<Button>> MenuDisplay::getListButtons() {
    return this->listButtons;
}



