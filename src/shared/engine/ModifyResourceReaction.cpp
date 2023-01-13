#include "ModifyResourceReaction.h"
#include "state/Player.h"
#include <iostream>
using namespace engine;
using namespace std;
using namespace state;

ModifyResourceReaction::ModifyResourceReaction(const state::State& state, int amount, Resource resType, int idPlayer){
    this->player=state.getSpecificPlayer(idPlayer);
    this->amount=amount;
    this->resType=resType;
}

ModifyResourceReaction::~ModifyResourceReaction ()= default;


void ModifyResourceReaction::execute (){
    player->modifyResource(resType,amount);
}

//resource gain is only forbidden when it would put a production value below 0, except for gold which is allowed to;
bool ModifyResourceReaction::query (){
    return player->isPossibleToModifyResource(resType,amount);
}

void ModifyResourceReaction::procNotification (){
}