#include "CardBoard.h"

using namespace std;
using namespace state;

CardBoard::CardBoard() {

}

CardBoard::~CardBoard() {

}

std::unordered_map<std::string, std::string> CardBoard::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(const auto& card : listCards) {
        uiData.insert(card.serializeUiData());
    }
    for(const auto& badge : badgesPlayed) {
        auto strBadgeData = to_string(badge.first) + "," + to_string(badge.second);
        uiData.insert({"Badge", strBadgeData});
    }
    return uiData;
}


