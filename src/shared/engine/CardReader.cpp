#include <functional>

#include "CardReader.h"

#include <../../extern/jsoncpp-1.8.0/json/json.h>
#include "../constants.hpp"
#include "DrawCardReaction.h"
#include "ModifyResourceReaction.h"
#include "PlaceTileReaction.h"
#include "IncreaseGPReaction.h"

using namespace std;
using namespace engine;

using CostMap = std::map<int, int>;

std::map<string, state::Badge> BadgeMap = {{"NONE", state::NONE},
                                           {"BUILDING", state::BUILDING},
                                           {"SPACE", state::SPACE},
                                           {"B_ENERGY", state::B_ENERGY},
                                           {"SCIENCE", state::SCIENCE},
                                           {"JOVIAN", state::JOVIAN},
                                           {"EARTH", state::EARTH},
                                           {"B_PLANT", state::B_PLANT},
                                           {"MICROBE", state::MICROBE},
                                           {"ANIMAL", state::ANIMAL},
                                           {"B_CITY", state::B_CITY},
                                           {"EVENT", state::EVENT},
                                           {"VENUS", state::VENUS}};

std::map<string, int> ReactionMap = {{"IncreaseGPReaction", 0},
                                   {"ModifyRessourceReaction", 1},
                                   {"PlaceTileReaction", 2},
                                   {"DrawCardReaction", 3}};

CardReader::CardReader() {

}

CardReader::~CardReader() {

}

// Helper function that gets the
bool checkCondition(const shared_ptr<state::State> &state, const string &conditionType, int conditionValue) {
    bool isConditionVerified = false;

    if(conditionType == "minOxy") {
        if(conditionValue >= state->getGlobalParameters()->getOxygen())
            isConditionVerified = true;
    }
    else if(conditionType == "maxOxy") {
        if(conditionValue <= state->getGlobalParameters()->getOxygen())
            isConditionVerified = true;
    }
    else if(conditionType == "minOcean") {
        if(conditionValue >= state->getGlobalParameters()->getNumberOcean())
            isConditionVerified = true;
    }
    else if(conditionType == "maxOcean") {
        if(conditionValue <= state->getGlobalParameters()->getNumberOcean())
            isConditionVerified = true;
    }
    else if(conditionType == "minTemp") {
        if(conditionValue >= state->getGlobalParameters()->getTemp())
            isConditionVerified = true;
    }
    else if(conditionType == "maxTemp") {
        if(conditionValue <= state->getGlobalParameters()->getTemp())
            isConditionVerified = true;
    }
    else if(conditionType == "science") {

    }

    return isConditionVerified;
}

/*
 * Reads the content of cardID and store the information in useful data structures
 * Returns 0 if the operation was successful, 1 otherwise
 */

int CardReader::parseCard(int idCard, const shared_ptr<state::State>& state) {
    int status = 0;

    EffectMap effects = {{0, {15000}},
                         {1, {3, 4}}};
    BadgeMap badges = {{0, {state::BUILDING, state::B_PLANT}},
                       {1, {state::SCIENCE, state::SCIENCE}}};
    CostMap costs = {{0, 12},
                     {1, 35}};

    for (const auto &badge: badges[idCard]) {
        this->listBadges.push_back(badge);
    }
    this->cost = costs[idCard];

    // Creates the reaction to make the player pay
    auto currentPlayerId = state->getCurrentPlayer()->getId();
    auto payReactionTmp = make_shared<ModifyResourceReaction>(*state, -cost, state::GOLD, currentPlayerId);
    payReaction.push_back(payReactionTmp);

    // Reads the card effects and adds reaction accordingly
    shared_ptr<Reaction> newReaction;
    for (const auto &effect: effects[idCard]) {
        switch (effect) {
            case 0:
                newReaction = shared_ptr<IncreaseGPReaction>();
                break;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
        }
    }

    return status;
     */
}

// Clears every table to free the shared pointers
void CardReader::clear() {
    instantReactions.clear();
    permanentReactions.clear();
    payReaction.clear();
    listBadges.clear();
    cost = 0;
}

const std::vector<state::Badge> &CardReader::getListBadges() const {
    return this->listBadges;
}

int CardReader::getCost() const {
    return this->cost;
}

const std::vector<std::shared_ptr<Reaction>> &CardReader::getInstantReactions() const {
    return this->instantReactions;
}

const std::vector<std::shared_ptr<Reaction>> &CardReader::getPayReaction() const {
    return this->payReaction;
}
