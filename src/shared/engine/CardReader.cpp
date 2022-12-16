#include "CardReader.h"

#include "DrawCardReaction.h"
#include "ModifyResourceReaction.h"
#include "PlaceTileReaction.h"
#include "IncreaseGPReaction.h"

using namespace std;
using namespace engine;

using EffectMap = std::map<int, std::vector<int>>;
using BadgeMap = std::map<int, std::vector<state::Badge>>;
using CostMap = std::map<int, int>;

CardReader::CardReader() {

}

CardReader::~CardReader() {

}

/*
 * Reads the content of cardID and store the information in useful data structures
 * Returns 0 if the operation was successful, 1 otherwise
 */

int CardReader::parseCard(int idCard, const shared_ptr<state::State>& state) {
    int status = 0;

    EffectMap effects = {{0, {1, 2}},
                         {1, {3, 4}}};
    BadgeMap badges = {{0, {state::BUILDING, state::B_PLANT}},
                       {1, {state::SCIENCE, state::SCIENCE}}};
    CostMap costs = {{0, 12},
                     {1, 35}};

    this->listBadges = badges[idCard];
    this->cost = costs[idCard];

    // Creates the reaction to make the player pay
    auto currentPlayerId = state->getCurrentPlayer()->getId();
    auto payReactionTmp = make_shared<ModifyResourceReaction>(*state, cost, state::GOLD, currentPlayerId);
    payReaction.push_back(std::move(payReactionTmp));


    // Reads the card effects and adds reaction accordingly
    shared_ptr<Reaction> newReaction;
    for (const auto &effect: effects[idCard]) {
        switch (effect) {
            case 0:
                newReaction = shared_ptr<IncreaseGPReaction>();
                break;
            case 1:
                newReaction = shared_ptr<ModifyResourceReaction>();
                break;
            case 2:
                newReaction = shared_ptr<PlaceTileReaction>();
                break;
            case 3:
                newReaction = shared_ptr<DrawCardReaction>();
                break;
            default:
                newReaction = nullptr;
                break;
        }

        if (newReaction != nullptr) {
            instantReactions.push_back(std::move(newReaction));
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
