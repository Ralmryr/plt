#include "IncreaseGPReaction.h"
#include <iostream>
#include "../constants.hpp"

using namespace engine;
using namespace std;

IncreaseGPReaction::IncreaseGPReaction (const state::State& state, int amount, std::string paramName){
    this->globalParameters = state.getGlobalParameters();
    this->amount = amount;
    this->paramName=paramName;
    this->reactionType=engine::IncreaseGP;
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


string IncreaseGPReaction::query (){
    int currentParameters;
    string errMessage;

    if(paramName=="oxygen"){
        currentParameters=globalParameters->getOxygen();
        if(currentParameters+amount>MAX_OXYGEN){
            errMessage = "Too much oxygen";
        }
    }else if(paramName=="temperature"){
        currentParameters=globalParameters->getTemp();
        if(currentParameters+amount>MAX_TEMPERATURE){
            errMessage = "Too much temperature";
        }
    }else if(paramName=="ocean"){
        currentParameters=globalParameters->getNumberOcean();
        if(currentParameters+amount>MAX_OCEAN) {
            errMessage = "Too much oceans";
        }
    }

    return errMessage;
}
void IncreaseGPReaction::procNotification () {
}