#include "BadgeScene.h"
#include <iostream>

using namespace std;
using namespace render;
using namespace std;

void render::BadgeScene::update(const std::unordered_map<std::string, std::string> &data) {
    // Seperate it into badgeData

    unordered_map<string, string> badgeData;
    int index = 1;
    string strBadge = "badge " + to_string(index);
    // Get all the badges amounts
    while (data.find(strBadge) != data.end()) {
        string strData = data.at(strBadge);
        badgeData.insert({strBadge, strData});
        strBadge = "badge " + to_string(++index);
    }
    popupBadge->update(badgeData);
}

void render::BadgeScene::draw(sf::RenderWindow &window) {
    popupBadge->draw(window);
}

render::BadgeScene::BadgeScene() {
    popupBadge = make_unique<PopupBadge>();
    transparent = true;
}

std::vector<std::shared_ptr<Button>> BadgeScene::getListButtons() {
    return popupBadge->getListButtons();
}

BadgeScene::~BadgeScene() = default;


