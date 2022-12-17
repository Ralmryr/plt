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

    cout << "Reaction constructed" << endl;
}

ModifyResourceReaction::~ModifyResourceReaction ()= default;


void ModifyResourceReaction::execute (){
    player->getResourceBoard().modifyResource(resType,amount);
    cout << "Reaction executed : " << amount << endl;
}

//resource gain is only forbidden when it would put a production value below 0, except for gold which is allowed to;
bool ModifyResourceReaction::query (){
    if(resType == IRON_PROD ||resType == TITANIUM_PROD || resType == PLANT_PROD ||resType == ENERGY_PROD || resType == HEAT_PROD){
        std::unordered_map<Resource, int> resourceCurrent = player->getResourceBoard().getResourceMap();
        if (resourceCurrent[resType]+amount<0) return false;
    }

    cout << "Reaction queried" << endl;
    return true;
}

void ModifyResourceReaction::procNotification (){
    cout << "Reaction destroyed" << endl;
}