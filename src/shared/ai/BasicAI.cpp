//
// Created by arthur on 19/12/22.
//


#include "BasicAI.h"

#include <utility>

using namespace ai;
using namespace std;

ai::BasicAI::BasicAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
}
ai::BasicAI::~BasicAI()= default;


void ai::BasicAI::playTurn(){


    int toPlay = chooseBestCard();
    if(toPlay>=0);
        //play(chooseBestCard())   joue la carte
    else passTurn();

    //do this twice because every player has up to 2 possible action
    toPlay = chooseBestCard();
    if(toPlay>=0);
        //play(chooseBestCard())   joue la carte
    else passTurn();

    //call an END_TURN event in manager;
}



int ai::BasicAI::chooseBestCard() { //return the position/cardddID ? of the card to play in hand
    bool playable=false;
    int card = 0;
    while (!playable){
        if(0) //condition remplis des qu'une querry pour jouer une carte est valide
            //lance un event de querry pour jouer la carte numero "card" de sa main.
            card+=1;
            //si carte > hand size, renvoie -1
        else playable =true;
    }

    return card;
}

std::pair<int, int> ai::BasicAI::findBestPosition(state::TileType tile) {
    std::pair<int, int> Coord;
    if(tile ==state::NOCTIS || tile ==state::GANYMEDE || tile ==state::PHOBOS){
        //place on reserved tile
        for (const auto &key: state->getBoard()->getListReserved()) {
            if (key.second == tile)
                Coord = key.first;
        }
    }
    else {
        bool isValid = false;
        while (!isValid) {
            Coord.first = rand() % 9 - 4;
            Coord.second = rand() % 9 - 4;
            if (state->getBoard()->isPossibleToPlaceTile(Coord,tile))
                isValid = true;
        }
    }
    return Coord;
}
