#include "CardScene.h"

void render::CardScene::update(const std::unordered_map<std::string, std::string> &data) {
    popupCards.update(data);
}

void render::CardScene::draw(sf::RenderWindow &window) {
    popupCards.draw(window);
}
