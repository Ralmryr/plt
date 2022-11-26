#include "Scene.h"

#include <utility>
#include <iostream>

using namespace std;

render::Scene::Scene() {
    this->popupBlueCards=PopupCard();
    this->popupHandCards=PopupCard();
    this->playerScoreDisplay=PlayerScoreDisplay();
    this->globalParametersDisplay=GlobalParametersDisplay();
    this->boardDisplay=BoardDisplay();
    this->menu=MenuDisplay();
    this->stdProject = StdProjectDisplay();
}

render::Scene::~Scene() {

}

void render::Scene::draw(sf::RenderWindow& window) {
    boardDisplay.draw(window);
    globalParametersDisplay.draw(window);
    stdProject.draw(window);
    playerScoreDisplay.draw(window);
    menu.draw(window);
    //popupBadge.draw(window);
    //popupBlueCards.draw(window);
    popupHandCards.draw(window);
}

void render::Scene::update() {
    // Board data
    auto boardData = dataProvider->provideBoardData();
    boardDisplay.update(boardData);

    // GlobalParam data
    auto globalParamData = dataProvider->provideGlobalParameters();
    globalParametersDisplay.update(globalParamData);

    // PlayerData
    auto playerData = dataProvider->providePlayerData(2);

    // Separate it into resourceData
    unordered_map<string, string> resourceData;
    int index = 1;
    string strResource = "resource " + to_string(index);
    // While a resource is still present in the map
    while(playerData.find(strResource) != playerData.end()){
        string strData = playerData.at(strResource);
        resourceData.insert({strResource, strData});
        strResource = "resource " + to_string(++index);
    }
    menu.update(resourceData);

    // Seperate it into cardsHandData
    unordered_map<string, string> cardsHandData;
    index = 0;
    string strCard = "idCardHand " + to_string(index);
    // While the player still has cards in his hands
    while(playerData.find(strCard) != playerData.end()) {
        string strData = playerData.at(strCard);
        cardsHandData.insert({strCard, strData});
        strCard = "idCardHand " + to_string(++index);
    }
    popupHandCards.update(cardsHandData);

    auto scoreData = dataProvider->provideScoreData();
    playerScoreDisplay.update(scoreData);

    /*popupBadge.update();
    popupBlueCards.update();
    popupHandCards.update();*/

}

void render::Scene::hookData(std::shared_ptr<state::RenderAPI> dataProvider) {
    this->dataProvider = dataProvider;
}
