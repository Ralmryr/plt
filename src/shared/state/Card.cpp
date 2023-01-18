//
// Created by cleme on 21/11/22.
//
#include "Card.h"

#include <utility>

using namespace state;
using namespace std;

Card::Card(int id, int cost, vector<Badge> listBadges) : id(id), listBadges(std::move(listBadges)), cost(cost){

}

Card::~Card() {

}

// [ "idCard" : "id,cost,listBadge" ]
std::pair<std::string, std::string> Card::serializeUiData() const {
    std::pair<string, string> uiData;
    uiData.first = "idCard";
    string data = to_string(id) + "," + to_string(cost) + ",";
    for (const auto &badge: listBadges) {
        data += to_string(badge) + ",";
    }
    uiData.second = data;
    return uiData;
}
