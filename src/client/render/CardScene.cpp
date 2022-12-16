#include "CardScene.h"

void render::CardScene::update(const std::unordered_map<std::string, std::string> &data) {
    popupHandCards.update(data);
    popupBlueCards.update(data);
}

void render::CardScene::draw(sf::RenderWindow &window) {
    popupHandCards.draw(window);
    popupBlueCards.draw(window);
}
