//
// Created by cleme on 21/11/22.
//
#include "Card.h"

using namespace state;
using namespace std;

Card::Card(int id) : id(id){
    this->id = id;
}

Card::~Card() {

}

// [ "idCard" : "id" ]
std::pair<std::string, std::string> Card::serializeUiData() const {
    std::pair<string, string> uiData;
    uiData.first = "idCard";
    uiData.second = to_string(id);
    return uiData;
}
