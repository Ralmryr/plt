//
// Created by cleme on 21/10/22.
//

#include "ParameterObserver.h"

state::ParameterObserver::ParameterObserver(state::GlobalParameters *parameters) : globalParameters(parameters){

}

state::ParameterObserver::~ParameterObserver() {
    delete this->globalParameters;
}
