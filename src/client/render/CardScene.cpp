#include "CardScene.h"

using namespace std;
using namespace render;

render::CardScene::CardScene() {
    popupCards = make_unique<PopupCard>();
    transparent = true;
}

render::CardScene::~CardScene() = default;

void render::CardScene::update(const std::unordered_map<std::string, std::string> &data) {
    // Seperate it into cardsHandData
    unordered_map<string, string> cardsHandData;
    int index = 0;
    string strCard = "idCardHand " + to_string(index);
    // While the player still has cards in his hands
    while (data.find(strCard) != data.end()) {
        string strData = data.at(strCard);
        cardsHandData.insert({strCard, strData});
        strCard = "idCardHand " + to_string(++index);
    }
    popupCards->update(cardsHandData);
}

void render::CardScene::draw(sf::RenderWindow &window) {
    popupCards->draw(window);
}

vector<std::shared_ptr<Button>> render::CardScene::getListButtons() {
    return popupCards->getListButtons();
}
