#include "GlobalParameters.h"
#include "../constants.hpp"

using namespace std;
using namespace state;

GlobalParameters::GlobalParameters() {
    this->temp = 0;
    this->numberOcean = STARTING_OCEAN;
    this->oxygen = 0;
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

int GlobalParameters::getOxygen() const {
    return oxygen;
}
void GlobalParameters::setOxygen(int oxygen) {
    this->oxygen=oxygen;
}

int GlobalParameters::getTemp() const{
    return temp;
}
void GlobalParameters::setTemp(int temp){
    this->temp=temp;
}
int GlobalParameters::getNumberOcean() const{
    return numberOcean;
}
void GlobalParameters::setNumberOcean(int numberOcean){
    this->numberOcean=numberOcean;
}