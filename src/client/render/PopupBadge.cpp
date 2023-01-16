#include <iostream>
#include "PopupBadge.h"

using namespace render;
using namespace std;

PopupBadge::PopupBadge() {
    sf::Vector2f vframeImage;
    sf::Vector2f vcloseButton;
    sf::Vector2f vbadge;

    this->frameImage = make_shared<Image>("animal.png", vframeImage);
    this->closeButton = make_shared<Button>("animal.png", vcloseButton);
    this->badgesImage = make_shared<Image>("animal.png", vbadge);
    this->listComponents.push_back(frameImage);
    this->listComponents.push_back(closeButton);

    this->listButtons.push_back(closeButton);
}

PopupBadge::~PopupBadge() = default;

void PopupBadge::update(const unordered_map<string,string>& data) {
    for (auto const &dataEl: data) {
        string badge = dataEl.second.substr(0, dataEl.second.find(","));
        string amount = dataEl.second.substr(1, dataEl.second.find(","));
        float xOriginBadge=0;
        float yOriginBadge=0;
        float indexBetweenBadges=0;

        int badgeID = stoi(badge);
        this->listComponents.push_back(make_shared<Text>(Text(amount,
                                                              sf::Vector2f(xOriginBadge,yOriginBadge+(badgeID-1)*indexBetweenBadges))));
    }
}

void PopupBadge::draw(sf::RenderWindow& window){
    if(isOpen) { // if the popup is open we draw all the components
        for(const auto &component : this->listComponents){
            window.draw(*component);
        }
    }
}

std::vector<std::shared_ptr<Button>> PopupBadge::getListButtons() {
    return listButtons;
}
