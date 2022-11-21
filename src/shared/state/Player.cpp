//
// Created by cleme on 21/11/22.
//

#include "Player.h"

using namespace std;
using namespace state;

Player::Player() {

}

Player::~Player() {

}

std::unordered_map<std::string, std::string> Player::serializeUiData() const {
    unordered_map<string, string> uiData;
    auto resData = resourceBoard->serializeUiData();
    auto cardBoardData = cardBoard->serializeUiData();
    auto cardHandData = cardsHand->serializeUiData();

    uiData.insert(resData.begin(), resData.end());
    uiData.insert(cardBoardData.begin(), cardBoardData.end());
    uiData.insert(cardHandData.begin(), cardHandData.end());
    return uiData;
}
