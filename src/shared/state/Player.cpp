#include "Player.h"
#include <iostream>

using namespace std;
using namespace state;

Player::Player(int id) {
    this->id = id;
    this->name = "Player" + to_string(id);
    this->resourceBoard = ResourceBoard();
    this->cardsHand = CardsHand();
    this->cardBoard = CardBoard();
}

Player::~Player() {

}

/*
 *  [   "resource i" : "amount"
 *      "idCardBoard i" : "id"
 *      "badge i" : "badge, amount"
 *      "idCardHand i" : "id" ]
 */
std::unordered_map<std::string, std::string> Player::serializeUiData() const {
    unordered_map<string, string> uiData;
    auto resData = resourceBoard.serializeUiData();
    auto cardBoardData = cardBoard.serializeUiData();
    auto cardHandData = cardsHand.serializeUiData();

    uiData.insert(resData.begin(), resData.end());
    uiData.insert(cardBoardData.begin(), cardBoardData.end());
    uiData.insert(cardHandData.begin(), cardHandData.end());
    return uiData;
}
ResourceBoard& Player::getResourceBoard(){
    return this->resourceBoard;
}

CardsHand& Player::getCardsHand(){
    return this->cardsHand;
}

int Player::getId() const {
    return this->id;
}

void Player::modifyResource(Resource resource, int amount) {
    resourceBoard.modifyResource(resource,amount);
}

bool Player::isPossibleToModifyResource(Resource resource, int amount) {
    return resourceBoard.isPossibleToModifyResource(resource,amount);
}

void Player::setForcedEndTurn(bool forcedEndTurn) {
    this->forcedEndTurn = forcedEndTurn;
}
