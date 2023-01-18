#include "CardScene.h"

using namespace std;
using namespace render;

// Transforms [ "<key> i" : "id,cost,badges" ] into [ "id" : "cost,badges" ]
// key will be either "idCardBoard" or "idCardHand"
static unordered_map<string, string> separateCardData(const unordered_map<string, string> &data, string key);

render::CardScene::CardScene(bool blueCard) {
    this->blueCard = blueCard;
    popupCards = make_unique<PopupCard>(blueCard);
    transparent = true;
}

render::CardScene::~CardScene() = default;

void render::CardScene::update(const std::unordered_map<std::string, std::string> &data) {


    //------BLUE CARDS---------
    if(blueCard){
        // Seperate it into cardBoardData
        auto cardBoardData = separateCardData(data, "idCardBoard");

        popupCards->update(cardBoardData);
    }
    //------NORMAL CARDS---------
    else{
        // Seperate it into cardHandData
        auto cardHandData = separateCardData(data, "idCardHand");
        popupCards->update(cardHandData);
    }
}

void render::CardScene::draw(sf::RenderWindow &window) {
    popupCards->draw(window);
}

vector<std::shared_ptr<Button>> render::CardScene::getListButtons() {
    return popupCards->getListButtons();
}

static unordered_map<string, string> separateCardData(const unordered_map<string, string> &data, string key) {
    unordered_map<string, string> returnData;

    key += " ";
    int index = 0;
    string strCard = key + to_string(index);
    // While the player still has cards in his hands
    while (data.find(strCard) != data.end()) {
        string strData = data.at(strCard);

        // Gets the cardID and deletes it from data
        size_t pos = strData.find(',');
        string idCardStr = strData.substr(0, pos);
        strData.erase(0, pos + 1);

        // The data looks like [ "id" : "cost,listBadge" ]
        returnData.insert({idCardStr, strData});
        strCard = key + to_string(++index);
    }

    return returnData;
}