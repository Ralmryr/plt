#include "PayScene.h"

using namespace std;
using namespace render;

render::PayScene::PayScene() {
    popupPay = make_unique<PopupPay>();
    transparent = true;
}

void render::PayScene::update(const std::unordered_map<std::string, std::string> &data) {
    unordered_map<string, string> cardsHandData;
    int index = 0;
    string strCard = "idCardHand " + to_string(index);
    // While the player still has cards in his hands
    while (data.find(strCard) != data.end()) {
        string strData = data.at(strCard);
        cardsHandData.insert({strCard, strData});
        strCard = "idCardHand " + to_string(++index);
    }
    popupPay->update(data);
}

void render::PayScene::draw(sf::RenderWindow &window) {
    popupPay->draw(window);
}

std::vector<std::shared_ptr<Button>> PayScene::getListButtons() {
    return popupPay->getListButtons();
}

void render::PayScene::setCardId(int cardId) {
    this->popupPay->setCardId(cardId);
}

PayScene::~PayScene() = default;




