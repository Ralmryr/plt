#include "DrawCardReaction.h"

using namespace engine;
using namespace std;
using namespace state;


DrawCardReaction::DrawCardReaction (State state, int idPlayer){
    /*
    std::shared_ptr<state::Player> player;
     */
    this->player= state.getSpecificPlayer(idPlayer);
    this->deck= state.getDeck();
}

DrawCardReaction::~DrawCardReaction ()= default;


void DrawCardReaction::execute (){
    this->player->getCardsHand().Draw(*deck);
}

bool DrawCardReaction::query (){
    if (deck->getSize()!=0)
        return true;
    else return false;
}
void DrawCardReaction::procNotification (){

}
