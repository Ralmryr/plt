#include "PlaceTileScene.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#include <iostream>

using namespace std;
using namespace render;

PlaceTileScene::PlaceTileScene() {
    boardDisplay = make_unique<BoardDisplay>();

    sf::Vector2f boardButtonPos = {20.f, 20.f};
    boardButton = make_shared<Button>("popupFrame.png", boardButtonPos);

    sf::Vector2f centerBoard = {960.f, 420.f};
    float offsetX = 74.f;
    float offsetY = 68.f;

    // [ (960, 420) : (0, 0) ] par exemple
    int joe = 1;
    int mama = 4;
    for (int y = -4; y < 5; y++) {
        if(y<=0) joe--;
        if(y>0) mama--;
        for (int x = joe; x <= mama; x++) {
            sf::Vector2i hexCoords(x, y);
            sf::Vector2f screenCoords;
            screenCoords.x = offsetX*hexCoords.x + offsetX*hexCoords.y*0.5f + centerBoard.x;
            screenCoords.y = centerBoard.y - y*offsetY;
            tilesCoordMap.emplace_back(screenCoords, hexCoords);
        }
    }
}

std::vector<std::shared_ptr<Button>> PlaceTileScene::getListButtons() {
    return {};
}

void PlaceTileScene::update(const unordered_map<std::string, std::string> &data) {
    boardDisplay->update(data);
}

void PlaceTileScene::draw(sf::RenderWindow &window) {
    boardDisplay->draw(window);
}

void PlaceTileScene::onClick(sf::Vector2f mousePos) {
    auto mouseX = mousePos.x;
    auto mouseY = mousePos.y;

    float minDistance = MAXFLOAT;
    size_t indexMin = 0;
    for (size_t i = 0; i < tilesCoordMap.size(); i++) {
        sf::Vector2f tileCoords = tilesCoordMap[i].first;
        float distanceFromClick = sqrt(pow(tileCoords.x - mouseX, 2) + pow(tileCoords.y - mouseY, 2));
        if(distanceFromClick <= minDistance) {
            minDistance = distanceFromClick;
            indexMin = i;
        }
    }

    sf::Vector2i tileClicked = tilesCoordMap[indexMin].second;
}

PlaceTileScene::~PlaceTileScene() = default;


