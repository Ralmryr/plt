//
// Created by arthur on 07/12/22.
//

#include "Deck.h"
#include <algorithm>
#include <random>

using namespace std;
using namespace state;

//generate a deck of the given size
Deck ::Deck(int size) {
    //remove cards that couldn't be implemented then shuffle the dec
    std::vector<int> RemovedCard = {0,3,9,10,11,20,24,25,26,27,28,30,31,32,42,100,101,104,108,109,119,61,64,65,66,67,72,81,83,84,87,90};

    int i;
    for(i = 0; i<size; i++){
        if(std::count(RemovedCard.begin(), RemovedCard.end(),i) == 0)
            this->deck.push_back(i);
    }

    std::shuffle(deck.begin(), deck.end(), std::random_device{});
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

const std::vector<int> &Deck::getDeck() const {
    return deck;
}


