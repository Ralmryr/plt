//
// Created by cleme on 21/11/22.
//

#include "GlobalParameters.h"

using namespace std;
using namespace state;

GlobalParameters::GlobalParameters() {
    this->temp = 6;
    this->numberOcean = 4;
    this->oxygen = 7;
}

GlobalParameters::~GlobalParameters() {

}

/* [    "Oxygen" : "amount"
        "Temperature" : "temperature"
        "NumberOceans" : "numberOceans" ]
 */
std::unordered_map<std::string, std::string> GlobalParameters::serializeUiData() const {
    unordered_map<string, string> uiData;
    uiData.insert({"Oxygen", to_string(oxygen)});
    uiData.insert({"Temperature", to_string(temp - 30)});
    uiData.insert({"NumberOceans", to_string(numberOcean)});

    return uiData;
}
