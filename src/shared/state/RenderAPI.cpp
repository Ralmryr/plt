//
// Created by cleme on 21/11/22.
//

#include "RenderAPI.h"

using namespace std;
using namespace state;

RenderAPI::RenderAPI() {

}

RenderAPI::~RenderAPI() {

}

/*
 *  [   "resource i" : "amount"
 *      "idCardBoard i" : "id"
 *      "badge i" : "badge, amount"
 *      "idCardHand i" : "id" ]
 */
std::unordered_map<std::string, std::string> RenderAPI::providePlayerData(int idPlayer) {
    return pPlayerList[idPlayer]->serializeUiData();
}

/*
 * [ "x, y" : "type, idOwner" ]
 */
std::unordered_map<std::string, std::string> RenderAPI::provideBoardData() {
    return pBoard->serializeUiData();
}

/* [    "Oxygen" : "amount"
        "Temperature" : "temperature"
        "NumberOceans" : "numberOceans" ]
 */
std::unordered_map<std::string, std::string> RenderAPI::provideGlobalParameters() {
    return pGlobalParameters->serializeUiData();
}

void RenderAPI::hookComponents(std::vector<std::shared_ptr<Player>> pPlayerList, std::shared_ptr<Board> pBoard,
                               std::shared_ptr<GlobalParameters> pGlobalParameters) {
    this->pPlayerList = pPlayerList;
    this->pBoard = pBoard;
    this->pGlobalParameters = pGlobalParameters;
}

unordered_map<std::string, std::string> RenderAPI::provideScoreData() {
    unordered_map<string, string> uiData;
    int idPlayer = 0;
    for(const auto& pPlayer : pPlayerList) {
        auto tmp = pPlayer->serializeUiData();
        string nt = tmp["NT"];
        uiData.insert({to_string(idPlayer), nt});
        idPlayer++;
    }
    return uiData;
}
