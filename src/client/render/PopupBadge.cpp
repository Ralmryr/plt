#include <iostream>
#include "PopupBadge.h"

using namespace render;
using namespace std;

PopupBadge::PopupBadge() {
    sf::Vector2f vframeImage;
    sf::Vector2f vcloseButton;
    sf::Vector2f vbadge;

    this->frameImage = make_shared<Image>("frameImage.png", vframeImage);
    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->badgesImage = make_shared<Image>("badgesImage", vbadge);
    this->listComponents.push_back(frameImage);
    this->listComponents.push_back(closeButton);
}

PopupBadge::~PopupBadge(){}

void PopupBadge::open(){
    this->isOpen = true;
}

void PopupBadge::close(){
    this->isOpen = false;
}

void PopupBadge::update(unordered_map<string,string> data) {
    for (auto const &dataEl: data) {
        string badge = dataEl.second.substr(0, dataEl.second.find(","));
        string amount = dataEl.second.substr(1, dataEl.second.find(","));
        float xOriginBadge=0;
        float yOriginBadge=0;
        float indexBetweenBadges=0;
        switch (stoi(badge)) {
            case 1://None
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+0*indexBetweenBadges))));
                break;
            case 2://Building
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+1*indexBetweenBadges))));
                break;
            case 3://Space
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+2*indexBetweenBadges))));
                break;
            case 4://Energy
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+3*indexBetweenBadges))));
                break;
            case 5://Science
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+4*indexBetweenBadges))));
                break;
            case 6://Jovian
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+5*indexBetweenBadges))));
                break;
            case 7://Earth
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+6*indexBetweenBadges))));
                break;
            case 8://Plant
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+7*indexBetweenBadges))));
                break;
            case 9://Microbe
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+0*indexBetweenBadges))));
                break;
            case 10://Animal
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+9*indexBetweenBadges))));
                break;
            case 11://City
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+10*indexBetweenBadges))));
                break;
            case 12://Event
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+11*indexBetweenBadges))));
                break;
            case 13://Venus
                this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                                      sf::Vector2f(xOriginBadge,yOriginBadge+12*indexBetweenBadges))));
                break;
        }
    }
}

void PopupBadge::draw(sf::RenderWindow& window){
    if(isOpen) { // if the popup is open we draw all the components
        for(const auto &component : this->listComponents){
            window.draw(*component);
        }
    }

}

void PopupBadge::setListComponents(const std::vector<std::shared_ptr<sf::Drawable>>& listComponents){

}