#include <functional>

#include "CardReader.h"

#include <iostream>
#include "../constants.hpp"
#include <fstream>
#include "DrawCardReaction.h"
#include "ModifyResourceReaction.h"
#include "PlaceTileReaction.h"
#include "IncreaseGPReaction.h"

using namespace std;
using namespace engine;

using CostMap = map<int, int>;
using EffectMap = map<int, vector<int>>;
using BadgeMap = map<int, vector<state::Badge>>;


std::map<string, state::Badge> badgeMap = {{"NONE", state::NONE},
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
std::map<string, state::Resource> ressourceMap = {{"GOLD", state::GOLD},
                                                  {"GOLD_PROD", state::GOLD_PROD},
                                                  {"IRON", state::IRON},
                                                  {"IRON_PROD", state::IRON_PROD},
                                                  {"TITANIUM", state::TITANIUM},
                                                  {"TITANIUM_PROD", state::TITANIUM_PROD},
                                                  {"PLANT", state::PLANT},
                                                  {"PLANT_PROD", state::PLANT_PROD},
                                                  {"ENERGY", state::ENERGY},
                                                  {"ENERGY_PROD", state::ENERGY_PROD},
                                                  {"HEAT", state::HEAT},
                                                  {"HEAT_PROD", state::HEAT_PROD},
                                                  {"NT", state::NT},
                                                  {"PV", state::PV}};

std::map<string, state::TileType> tileTypeMap = {{"FOREST",state::FOREST},
                                                 {"OCEAN",state::OCEAN},
                                                 {"CITY",state::CITY},
                                                 {"MINE",state::MINE},
                                                 {"FORBIDDEN",state::FORBIDDEN},
                                                 {"MOHOL",state::MOHOL},
                                                 {"NUKE",state::NUKE},
                                                 {"PRESERVED",state::PRESERVED},
                                                 {"ZOO",state::ZOO},
                                                 {"COMMERCIAL",state::COMMERCIAL},
                                                 {"CAPITAL",state::CAPITAL},
                                                 {"INDUSTRY",state::INDUSTRY},
                                                 {"NOCTIS",state::NOCTIS},
                                                 {"PHOBOS",state::PHOBOS},
                                                 {"GANYMEDE",state::GANYMEDE}};

std::map<string, int> reactionMap = {{"IncreaseGP", 0},
                                   {"ModifyResource", 1},
                                   {"PlaceTile", 2},
                                   {"DrawCard", 3}};


CardReader::CardReader() {
    ifstream ifs(RESS_PATH + "cards_description.json");
    reader.parse(ifs, cardsObj);
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

    return isConditionVerified;
}

/*
 * Reads the content of cardID and store the information in useful data structures
 * Returns 0 if the operation was successful, 1 otherwise
 */

int CardReader::parseCard(int idCard, const shared_ptr<state::State>& state) {
    int status = 0;



    auto effects = cardsObj[idCard-1]["effects"];
    auto badges = cardsObj[idCard-1]["badges"];
    this->cost = cardsObj[idCard-1]["cost"].asInt();
    for (const auto &badge : badges){
        this->listBadges.push_back(badgeMap[badge.asString()]);
    }


    // Creates the reaction to make the player pay
    auto currentPlayerId = state->getCurrentPlayer()->getId();
    auto payReactionTmp = make_shared<ModifyResourceReaction>(*state, -cost, state::GOLD, currentPlayerId);
    payReaction.push_back(payReactionTmp);


    // Reads the card effects and adds reaction accordingly
    shared_ptr<Reaction> newReaction;
    for (const auto &effect: effects) {
        switch (reactionMap[effect[1].asString()]) {
            case 0:
                newReaction = make_shared<IncreaseGPReaction>(*state, stoi(effect[2].asString()),
                                                              effect[3].asString());
                break;
            case 1:
                newReaction = make_shared<ModifyResourceReaction>(*state, stoi(effect[2].asString()),
                                                                  ressourceMap[effect[3].asString()],
                                                                  currentPlayerId);
                break;
            case 2:
                newReaction = make_shared<PlaceTileReaction>(*state,
                                                             pair<int, int>(stoi(effect[2].asString()), stoi(effect[3].asString())),
                                                             tileTypeMap[effect[4].asString()], currentPlayerId);
                break;
            case 3:
                newReaction = make_shared<DrawCardReaction>(*state, currentPlayerId);
                break;
        }

        if (effect[0].asString() == "Instant"){
            instantReactions.push_back(newReaction);
        }
        else if(effect[0].asString() == "Permanent"){
            instantReactions.push_back(newReaction);
        }
    }

    return status;


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
