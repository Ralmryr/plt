//
// Created by cleme on 21/11/22.
//

#include "ResourceBoard.h"

using namespace std;
using namespace state;


ResourceBoard::ResourceBoard() {
    // Initialize all resources at 0
    for(int res = R_FIRST+1; res != R_LAST; res++) {
        resourceMap.insert({Resource(res), 0});
    }
}

ResourceBoard::~ResourceBoard() {

}

std::unordered_map<std::string, std::string> ResourceBoard::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(const auto& res : resourceMap) {
        uiData.insert({to_string(res.first), to_string(res.second)});
    }

    return uiData;
}
