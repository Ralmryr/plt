//
// Created by cleme on 21/11/22.
//

#include "CardBoard.h"

using namespace std;
using namespace state;

CardBoard::CardBoard() {

}

CardBoard::~CardBoard() {

}

std::unordered_map<std::string, std::string> CardBoard::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(const auto& card : listCards) {
        uiData.insert(card.serializeUiData());
    }
    return uiData;
}


