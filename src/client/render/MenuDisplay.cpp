//
// Created by arthur on 21/11/22.
//

#include "MenuDisplay.h"
#include <iostream>

using namespace render;
using namespace std;



MenuDisplay :: MenuDisplay (){

    //define positions for all button and image in the menu
    sf::Vector2<float> vframe ;
    sf::Vector2<float> vResource ;
    sf::Vector2<float> vCard ;
    sf::Vector2<float> vBlueCard ;
    sf::Vector2<float> vBadge ;
    sf::Vector2<float> vPoints ;

    //define the size of all buttons
    sf::Vector2<float> sizeButtonCard;
    sf::Vector2<float> sizeBlueCardButton;
    sf::Vector2<float> sizeBadgeButton;

    //define all texts positions

    sf::Vector2<float> posBadgeText;
    sf::Vector2<float> posPVText;


    //define Images

    this->frameImage = make_shared<Image>(Image("badge_wild.png",vframe));
    this->resourcesImage = make_shared<Image>(Image("badge_wild.png",vResource));
    this->pvImage = make_shared<Image>(Image("mars.png",vPoints));

    //define buttons

    ClickableArea cardClick = ClickableArea();
    cardClick.setPosition(vCard);
    cardClick.setSize(sizeButtonCard);
    this->cardButton = make_shared<Button>(Button("card.png",cardClick,vCard));

    ClickableArea BlueCardClick = ClickableArea();
    BlueCardClick.setPosition(vBlueCard);
    BlueCardClick.setSize(sizeBlueCardButton);
    this->blueCardButton = make_shared<Button>(Button("blue_card.png",BlueCardClick,vBlueCard));

    ClickableArea BadgeClick = ClickableArea();
    BadgeClick.setPosition(vBadge);
    BadgeClick.setSize(sizeBadgeButton);
    this->badgeButton = make_shared<Button>(Button("badge_wild.png",BadgeClick,vBadge));

    //define all texts

    this->badgeText = make_shared<Text>(Text("Badges",posBadgeText));
    this->pvText = make_shared<Text>(Text("0",posPVText));

    listComponents.push_back(frameImage);
    listComponents.push_back(cardButton);
    listComponents.push_back(blueCardButton);
    listComponents.push_back(badgeButton);
    listComponents.push_back(badgeText);
    listComponents.push_back(pvImage);
    listComponents.push_back(pvText);
}

MenuDisplay::~MenuDisplay() {

}

void MenuDisplay::update(std::unordered_map<std::string,std::string> data) {
    //update ressources texts and pvtext
}

void MenuDisplay::draw (sf::RenderWindow& window){

}

