#include "DrawCardReaction.h"

using namespace engine;
using namespace std;
using namespace state;


DrawCardReaction::DrawCardReaction (const state::State& state, int idPlayer){
    /*
    std::shared_ptr<state::Player> player;
     */
    this->player= state.getSpecificPlayer(idPlayer);
    this->deck= state.getDeck();
}

DrawCardReaction::~DrawCardReaction ()= default;


void DrawCardReaction::execute (){
    this->player->getCardsHand().draw(deck);
}

string DrawCardReaction::query (){
    if (deck->getSize()!=0)
        return "";
    else return "No more cards";
}
void DrawCardReaction::procNotification (){

}
