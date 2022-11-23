
#include "MenuDisplay.h"
#include <iostream>

using namespace render;
using namespace std;



MenuDisplay :: MenuDisplay (){

    //define positions for all button and image in the menu
    sf::Vector2f vframe = {0, 850};
    sf::Vector2f vResource ;
    sf::Vector2f vCard = {900, 810};
    sf::Vector2f vBlueCard = {1225, 870};
    sf::Vector2f vBadge = {1475, 900};
    sf::Vector2f vPoints;

    //define the size of all sprites
    //sf::Vector2u sizeFrame = {1920, 230};
    //sf::Vector2u sizeRessource;
    sf::Vector2u sizeBlueCardButton = {150, 200};
    sf::Vector2u sizeBadgeButton;

    //define all texts positions

    sf::Vector2f posBadgeText;
    sf::Vector2f posPVText;


    //define Images

    this->frameImage = make_shared<Image>("menuFrame.png",vframe);
    this->resourceImage = make_shared<Image>("badge_wild.png",vResource);
    this->pvImage = make_shared<Image>("mars.png",vPoints);

    //define buttons

    ClickableArea cardClick = ClickableArea();
    cardClick.setPosition(vCard);
    this->cardButton = make_shared<Button>("card.png",cardClick,vCard);
    this->cardButton->setScale(0.55f);

    ClickableArea BlueCardClick = ClickableArea();
    BlueCardClick.setPosition(vBlueCard);
    this->blueCardButton = make_shared<Button>("blue.png",BlueCardClick,vBlueCard);
    this->blueCardButton->setSize(sizeBlueCardButton);

    ClickableArea BadgeClick = ClickableArea();
    BadgeClick.setPosition(vBadge);
    this->badgeButton = make_shared<Button>("badge_wild.png",BadgeClick,vBadge);
    this->badgeButton->setScale(1.2f);

    //define all texts

    this->badgeText = make_shared<Text>("Badges",posBadgeText);
    this->pvText = make_shared<Text>("0",posPVText);

    listComponents.push_back(frameImage);
    listComponents.push_back(cardButton);
    listComponents.push_back(blueCardButton);
    listComponents.push_back(badgeButton);
    //listComponents.push_back(badgeText);
    //listComponents.push_back(pvImage);
    //listComponents.push_back(pvText);
}

MenuDisplay::~MenuDisplay() = default;

void MenuDisplay::update(std::unordered_map<std::string,std::string> data) {
    //update resources texts and pvtext

    for(const auto& resource : data){
        int i = stoi(resource.first);
        string txt = resource.second;
        if(i%2==1){
            //one element in 2 correspond to a prod
            listResourceProd[(i-1)/2].setText(txt);
        }
        else{
            listResourceReserv[i/2].setText(txt);
        }
    }
}

void MenuDisplay::draw (sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }

}



