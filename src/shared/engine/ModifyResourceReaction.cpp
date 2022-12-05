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
ModifyResourceReaction::~ModifyResourceReaction (){

}
void ModifyResourceReaction::execute (){
    std::unordered_map<Resource, int> resourceMap = player->getResourceBoard().getResourceMap();
    resourceMap[resType] += amount;
}
bool ModifyResourceReaction::query (){
    return true;
}
void ModifyResourceReaction::procNotification (){

}