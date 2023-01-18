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

        // Gets the cardID and deletes it from data
        size_t pos = strData.find(',');
        string idCardStr = strData.substr(0, pos);
        strData.erase(0, pos + 1);

        // The data looks like [ "id" : "cost,listBadge" ]
        cardsHandData.insert({idCardStr, strData});
        strCard = "idCardHand " + to_string(++index);
    }

    auto ironStr = "resource " + to_string(state::IRON);
    auto goldStr = "resource " + to_string(state::GOLD);
    auto titaniumStr = "resource " + to_string(state::TITANIUM);
    cardsHandData.insert({ironStr, data.at(ironStr)});
    cardsHandData.insert({goldStr, data.at(goldStr)});
    cardsHandData.insert({titaniumStr, data.at(titaniumStr)});

    popupPay->update(cardsHandData);
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




