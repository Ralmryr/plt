#include "BadgeScene.h"

void render::BadgeScene::update(const std::unordered_map<std::string, std::string> &data) {
    popupBadge->update(data);
}

void render::BadgeScene::draw(sf::RenderWindow &window) {
    popupBadge->draw(window);
}
