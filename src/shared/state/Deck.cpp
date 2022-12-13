//
// Created by arthur on 07/12/22.
//

#include "Deck.h"

using namespace std;
using namespace state;

//generate a deck of the given size
Deck ::Deck(int size) {
    int i;
    for(i =1; i<size+1; i++){
        this->deck.insert(i);
    }
}

Deck :: ~Deck()= default;


void Deck::addCard(int cardID) {
    this->deck.insert(cardID);
}


bool Deck::removeCard(int cardID) {
    if (*deck.find(cardID)==cardID) {
        this->deck.erase(cardID);
        return true;
    }
    else return false;
}

int Deck::getSize() {
    return deck.size();

}


