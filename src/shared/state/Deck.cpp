//
// Created by arthur on 07/12/22.
//

#include "Deck.h"
#include <algorithm>

using namespace std;
using namespace state;

//generate a deck of the given size
Deck ::Deck(int size) {
    int i;
    for(i =1; i<size+1; i++){
        this->deck.push_back(i);
    }
}

Deck :: ~Deck()= default;


void Deck::addCard(int cardID) {
    this->deck.push_back(cardID);
}


bool Deck::removeCard(int cardID) {

}

int Deck::getSize() {
    return deck.size();

}

int Deck::drawCard() {
    auto topCard = deck.back();
    deck.pop_back();
    return topCard;
}


