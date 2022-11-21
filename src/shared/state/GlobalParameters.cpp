//
// Created by cleme on 21/11/22.
//

#include "GlobalParameters.h"

using namespace std;
using namespace state;

GlobalParameters::GlobalParameters() {

}

GlobalParameters::~GlobalParameters() {

}

std::unordered_map<std::string, std::string> GlobalParameters::serializeUiData() const {
    unordered_map<string, string> uiData;
    uiData.insert({"Oxygen", to_string(oxygen)});
    uiData.insert({"Temperature", to_string(temp)});
    uiData.insert({"NumberOceans", to_string(numberOcean)});

    return uiData;
}
