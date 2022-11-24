//
// Created by cleme on 21/11/22.
//

#include "ResourceBoard.h"

using namespace std;
using namespace state;


ResourceBoard::ResourceBoard() {
    // Initialize all resources at 0
    for(int res = R_FIRST+1; res != R_LAST; res++) {
        resourceMap.insert({Resource(res), 15});
    }

    resourceMap[GOLD_PROD] = 52;
    resourceMap[IRON] = 37;
    resourceMap[HEAT] = -78;

    resourceMap[NT] = 20;
    resourceMap[PV] = 0;
}

ResourceBoard::~ResourceBoard() {

}

/*
 *  [   "resource i" : "amount"
 *      "PV" : "amount"
 *      "NT" : "amount"
 *  ]
 */
std::unordered_map<std::string, std::string> ResourceBoard::serializeUiData() const {
    unordered_map<string, string> uiData;
    for(int i = R_FIRST+1; i != R_LAST; i++) {
        auto resAmount = resourceMap.at(Resource(i));
        uiData.insert({"resource " + to_string(i), to_string(resAmount)});
    }
    uiData.insert({"PV", to_string(resourceMap.at(PV))});
    uiData.insert({"NT", to_string(resourceMap.at(NT))});

    return uiData;
}
