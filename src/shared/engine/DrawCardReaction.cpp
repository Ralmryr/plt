#include "DrawCardReaction.h"

using namespace engine;
using namespace std;
using namespace state;


DrawCardReaction::DrawCardReaction (const state::State& state, int idPlayer){
    /*
    std::shared_ptr<state::Player> player;
    int newCard;
     */
    this->player=state.getSpecificPlayer(idPlayer);
}
DrawCardReaction::~DrawCardReaction (){

}
void DrawCardReaction::execute (){

}
bool DrawCardReaction::query (){
    return true;
}
void DrawCardReaction::procNotification (){

}
