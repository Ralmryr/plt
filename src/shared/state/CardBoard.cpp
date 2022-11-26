#include "CardBoard.h"

using namespace std;
using namespace state;

// Creates a list of cards with ids ranging from 80 to 89
CardBoard::CardBoard() {
    for(int i = 0; i < 10; i++) {
        listCards.emplace_back(80 + i);
    }
    for(int i = B_FIRST+1; i != B_LAST; i++) {
        badgesPlayed.insert({Badge(i), 0});
    }
}

CardBoard::~CardBoard() {

}

// Returns data of cards played and badge played
// [    "idCardBoard i" : "id",
//      "badge i" : "badge, amount" ]
std::unordered_map<std::string, std::string> CardBoard::serializeUiData() const{
    unordered_map<string, string> uiData;
    for(int i = 0; i < int(listCards.size()); i++) {
        auto cardData = listCards[i].serializeUiData();
        uiData.insert({"idCardBoard " + to_string(i), cardData.second});
    }
    for(int i = B_FIRST+1; i != B_LAST; i++) {
        auto amount = badgesPlayed.at(Badge(i));
        auto strBadgeData = to_string(i) + "," + to_string(amount);
        uiData.insert({"badge " + to_string(i), strBadgeData});
    }
    return uiData;
}


