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
    return pPlayerList[idPlayer]->serializeUiData();
}

std::unordered_map<std::string, std::string> UiDataProvider::provideBoardData() {
    return pBoard->serializeUiData();
}

std::unordered_map<std::string, std::string> UiDataProvider::provideGlobalParameters() {
    return pGlobalParameters->serializeUiData();
}

void UiDataProvider::hookComponents(std::vector<std::shared_ptr<Player>> pPlayerList, std::shared_ptr<Board> pBoard,
                                    std::shared_ptr<GlobalParameters> pGlobalParameters) {
    this->pPlayerList = pPlayerList;
    this->pBoard = pBoard;
    this->pGlobalParameters = pGlobalParameters;
}

unordered_map<std::string, std::string> UiDataProvider::provideScoreData() {
    unordered_map<string, string> uiData;
    int idPlayer = 0;
    for(const auto& pPlayer : pPlayerList) {
        auto tmp = pPlayer->serializeUiData();
        string nt = tmp[to_string(NT)];
        uiData.insert({to_string(idPlayer), nt});
        idPlayer++;
    }
    return uiData;
}
