//
// Created by cleme on 21/11/22.
//

#include "CardsHand.h"

using namespace std;
using namespace state;


// Creates a list of cards with ids ranging from 70 to 79
CardsHand::CardsHand() {
    for(int i = 0; i < 10; i++) {
        listCards.emplace_back(70 + i);
    }
}

CardsHand::~CardsHand() {

}

// Returns the data of cards in hand
// [ "idCardHand i" : "id" ]
std::unordered_map<std::string, std::string> CardsHand::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(int i = 0; i < int(listCards.size()); i++) {
        auto CardData = listCards[i].serializeUiData();
        uiData.insert({"idCardHand " + to_string(i), CardData.second});
    }
    return uiData;
}
