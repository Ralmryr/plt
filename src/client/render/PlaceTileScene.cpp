#include "PlaceTileScene.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace render;

PlaceTileScene::PlaceTileScene() {
    boardDisplay = make_unique<BoardDisplay>();

    sf::Vector2f boardButtonPos = {20.f, 20.f};
    boardButton = make_shared<Button>("popupFrame.png", boardButtonPos);
}

std::vector<std::shared_ptr<Button>> PlaceTileScene::getListButtons() {
    return {boardButton};
}

void PlaceTileScene::update(const unordered_map<std::string, std::string> &data) {
    boardDisplay->update(data);
}

void PlaceTileScene::draw(sf::RenderWindow &window) {
    boardDisplay->draw(window);
    window.draw(*boardButton);
}

PlaceTileScene::~PlaceTileScene() = default;


