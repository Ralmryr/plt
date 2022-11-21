//
// Created by cleme on 21/11/22.
//

#include "UiDataProvider.h"

using namespace std;
using namespace state;

UiDataProvider::UiDataProvider() {

}

UiDataProvider::~UiDataProvider() {

}

std::unordered_map<std::string, std::string> UiDataProvider::providePlayerData(int idPlayer) {
    return pPlayer->serializeUiData();
}

std::unordered_map<std::string, std::string> UiDataProvider::provideBoardData() {
    return pBoard->serializeUiData();
}

std::unordered_map<std::string, std::string> UiDataProvider::provideGlobalParameters() {
    return pGlobalParameters->serializeUiData();
}
