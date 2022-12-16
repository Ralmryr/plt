#include <fstream>
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

void CardReader::parseCard(int idCard) {
    Json::Reader reader;
    Json::Value obj;
    ifstream ifs(RESS_PATH + "cards_description.json");
    reader.parse(ifs, obj);

    this->cost = obj[idCard-1]["cost"].asInt();
    for (int i = 0; i < obj[idCard-1]["badges"].size(); i++){
        string badge = obj[idCard-1]["badges"][i].asString();
        this->listBadges.push_back(BadgeMap[badge]);
    }
    for (int j = 0; j < obj[idCard-1]["effects"].size(); j++){
        string effect = obj[idCard-1]["effects"][j].asString();
        string effectType = effect.substr(0, effect.find(":"));
        string reactionType = effect.substr(1, effect.find(":"));
        int c = ReactionMap[reactionType];
        shared_ptr<Reaction> newReaction;
        switch(c){
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
}
