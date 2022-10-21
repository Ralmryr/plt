//
// Created by ismail on 04/10/22.
//

#include "State.h"

state::State::State(state::GlobalParameters *globalParameters, state::Board *currentBoard)
    : board(currentBoard), currentParameters(globalParameters){

}

state::State::~State() {
    delete this->board;
    delete this->currentParameters;
}
