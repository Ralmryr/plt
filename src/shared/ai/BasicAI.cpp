//
// Created by arthur on 19/12/22.
//


#include "BasicAI.h"

#include <utility>

using namespace ai;
using namespace std;
using namespace engine;

ai::BasicAI::BasicAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
}
ai::BasicAI::~BasicAI()= default;


void ai::BasicAI::playTurn(){
    //check si des convertion plantes/chaleurs sont possibles

    //check si des projets standarts sont possibles

    if(!chooseBestCard())
        passTurn();

    //do this twice because every player has up to 2 possible action
    if(!chooseBestCard())
        passTurn();


    //call an END_TURN event in manager;
}


//play the best card
//return 1 if it successfully played a card
//return 0 if there is no card to play

int ai::BasicAI::chooseBestCard() {
    string err_msg="you can t play this card";
    int i=0;
    /*std::vector<state::Card> hand = player->getCardsHand().getListCards();
    while (!err_msg.empty()&& i!=hand.size()){
        int iDcard = hand[i].getId();
        EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = iDcard;
        manager->notify(eventDetails);

        err_msg=manager->getErrorMessage();
        i+=1;
    }*/
    if(err_msg.empty()) return 1;
    else return 0;
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
