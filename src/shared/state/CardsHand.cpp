//
// Created by cleme on 21/11/22.
//

#include "CardsHand.h"

using namespace std;
using namespace state;

CardsHand::CardsHand() {

}

CardsHand::~CardsHand() {

}

std::unordered_map<std::string, std::string> CardsHand::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(const auto& card : listCards) {
        uiData.insert(card.serializeUiData());
    }

    return uiData;
}
