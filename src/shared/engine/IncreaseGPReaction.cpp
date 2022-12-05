#include "IncreaseGPReaction.h"
#include <iostream>
#include "../constants.hpp"

using namespace engine;
using namespace std;


IncreaseGPReaction::IncreaseGPReaction (const state::State& state, int amount, std::string paramName){
    std::shared_ptr<state::GlobalParameters> currentGlobalParameters=state.getGlobalParameters();
    this->globalParameters =currentGlobalParameters;
    this->amount = amount;
    this->paramName=paramName;
}

IncreaseGPReaction::~IncreaseGPReaction (){};

void IncreaseGPReaction::execute (){
    if(paramName=="oxygen"){
        globalParameters->setOxygen(globalParameters->getOxygen()+amount);
    }else if(paramName=="temperature"){
        globalParameters->setTemp(globalParameters->getTemp()+amount);
    }else if(paramName=="ocean"){
        globalParameters->setNumberOcean(globalParameters->getNumberOcean()+amount);
    }else{
        cout <<"Increase GP reaction failed" << endl;
    }
}


bool IncreaseGPReaction::query (){
    int currentParameters;
    if(paramName=="oxygen"){
        currentParameters=globalParameters->getOxygen();
        if(currentParameters+amount>MAX_OXYGEN){
            return false;
        }else return true;
    }else if(paramName=="temperature"){
        currentParameters=globalParameters->getTemp();
        if(currentParameters+amount>MAX_TEMPERATURE){
            return false;
        }else return true;
    }else if(paramName=="ocean"){
        currentParameters=globalParameters->getNumberOcean();
        if(currentParameters+amount>MAX_OCEAN){
            return false;
        }else return true;
    }else{
        cout <<"Increase GP reaction query failed" << endl;
        return false;
    }
}
void IncreaseGPReaction::procNotification () {
}