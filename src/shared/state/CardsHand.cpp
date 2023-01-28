//
// Created by cleme on 21/11/22.
//

#include "CardsHand.h"
#include <algorithm>

using namespace std;
using namespace state;


CardsHand::CardsHand() {
    vector<Badge> listBadge = {EARTH, BUILDING};
    /*for(int i = 1; i < 24; i++) {
        listCards.emplace_back(i, 20, listBadge);
    }*/
}

CardsHand::~CardsHand() {

}

// Returns the data of cards in hand
// [ "idCardHand i" : "id,cost,listBadges" ]
std::unordered_map<std::string, std::string> CardsHand::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(int i = 0; i < int(listCards.size()); i++) {
        auto CardData = listCards[i]->serializeUiData();
        uiData.insert({"idCardHand " + to_string(i), CardData.second});
    }
    return uiData;
}

void CardsHand::addCard(std::shared_ptr<Card> card) {
    listCards.push_back(std::move(card));
}

void CardsHand::removeCard(int cardID) {
    auto newEnd = remove_if(listCards.begin(), listCards.end(), [cardID](const shared_ptr<Card>& card){
        return card->getId() == cardID;
    });
    listCards.erase(newEnd, listCards.end());
}













