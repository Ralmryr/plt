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

void CardReader::parseCard(int idCard) {
    EffectMap effects = {{0, {1, 2}},
                         {1, {3, 4}}};
    BadgeMap badges = {{0, {state::BUILDING, state::B_PLANT}},
                       {1, {state::SCIENCE, state::SCIENCE}}};
    CostMap costs = {{0, 12},
                     {1, 35}};

    this->listBadges = badges[idCard];
    this->cost = costs[idCard];

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
}
