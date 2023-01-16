//
// Created by cleme on 21/11/22.
//

#include "CardsHand.h"

using namespace std;
using namespace state;


// Creates a list of cards with ids ranging from 70 to 79
CardsHand::CardsHand() {
    for(int i = 1; i < 24; i++) {
        listCards.emplace_back(i);
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

void CardsHand :: draw(std::shared_ptr<Deck> deck){ //a modifier en utilisant le cardreader pour générer correctement la carte
    int IDcard = rand();
    if(deck->removeCard(IDcard)) {
        listCards.emplace_back(Card(IDcard));
    }
}


void CardsHand :: draw(std::shared_ptr<Deck> deck, int cardID){ //a modifier en utilisant le cardreader pour générer correctement la carte
    if(deck->removeCard(cardID)) {
        listCards.emplace_back(Card(cardID));
    }
}













