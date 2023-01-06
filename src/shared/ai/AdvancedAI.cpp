//
// Created by arthur on 19/12/22.
//

#include "AdvancedAI.h"

using namespace ai;
using namespace std;

ai::AdvancedAI::AdvancedAI(std::shared_ptr<state::State> state) {
    this->state=std::move(state);
}

ai::AdvancedAI::~AdvancedAI()= default;

void ai::AdvancedAI::playTurn() {}

int ai::AdvancedAI::chooseBestCard() {
    return 0;
}
