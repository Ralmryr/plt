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
 *      "idCardHand i" : "id"
 *      "idPlayer" : "id"
 *      ]
 */
std::unordered_map<std::string, std::string> RenderAPI::providePlayerData(int idPlayer = -1) {
    if(idPlayer == -1) {
        auto dataMap = pState->getCurrentPlayer()->serializeUiData();
        dataMap.insert({"idPlayer", to_string(pState->getCurrentPlayer()->getId())});
        return dataMap;
    }
    else {
        auto dataMap = pState->getCurrentPlayer()->serializeUiData();
        dataMap.insert({"idPlayer", to_string(idPlayer)});
        return dataMap;
    }
}

/* [    "idPlayer" : "NT"   ]
*/
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

void RenderAPI::hookComponents(const std::shared_ptr<State>& state) {
    this->pPlayerList = state->getListPlayers();
    this->pBoard = state->getBoard();
    this->pGlobalParameters = state->getGlobalParameters();
    this->pState = state;
}

std::unordered_map<std::string, std::string> RenderAPI::provideMainSceneData() {
    unordered_map<string, string> boardSceneData;

    auto gpData = provideGlobalParameters();
    auto boardData = provideBoardData();
    auto scoreData = provideScoreData();

    boardSceneData.insert(gpData.begin(), gpData.end());
    boardSceneData.insert(boardData.begin(), boardData.end());
    boardSceneData.insert(scoreData.begin(), scoreData.end());

    return boardSceneData;
}
