#include "Scene.h"
#include <iostream>

#include <utility>
#include <iostream>

using namespace std;

// This technique prevents the double call of the constructor of each class
render::Scene::Scene() : popupBlueCards(), popupHandCards(), playerScoreDisplay(), globalParametersDisplay(), boardDisplay(), menu(), stdProject(){
    engineAPI = make_shared<EngineAPI>();
}

render::Scene::~Scene() {

}

void render::Scene::draw(sf::RenderWindow& window) {
    if (currentScene == CARDS_HAND_VIEW || currentScene == BOARD_VIEW) {
    boardDisplay.draw(window);
    globalParametersDisplay.draw(window);
    stdProject.draw(window);
    playerScoreDisplay.draw(window);
    menu.draw(window);
    }
    if(currentScene == CARDS_HAND_VIEW) {
        popupHandCards.draw(window);
    }
}

void render::Scene::update() {

    // ------------------------------------- BOARD VIEW -----------------------------------
    if(currentScene == BOARD_VIEW) {
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
        while (playerData.find(strResource) != playerData.end()) {
            string strData = playerData.at(strResource);
            resourceData.insert({strResource, strData});
            strResource = "resource " + to_string(++index);
        }
        menu.update(resourceData);
    }

    // -------------------------------------- CARDS HAND VIEW -----------------------------------
    if(currentScene == CARDS_HAND_VIEW) {
        auto playerData = dataProvider->providePlayerData(2);

        // Seperate it into cardsHandData
        unordered_map<string, string> cardsHandData;
        int index = 0;
        string strCard = "idCardHand " + to_string(index);
        // While the player still has cards in his hands
        while (playerData.find(strCard) != playerData.end()) {
            string strData = playerData.at(strCard);
            cardsHandData.insert({strCard, strData});
            strCard = "idCardHand " + to_string(++index);
        }
        popupHandCards.update(cardsHandData);
    }

}

void render::Scene::hookData(std::shared_ptr<state::RenderAPI> dataProvider) {
    this->dataProvider = dataProvider;
}

void render::Scene::setScene(render::SceneID sceneID) {
    this->currentScene = sceneID;
    this->update();

    if(sceneID == BOARD_VIEW){
        vector<shared_ptr<Button>> listButtons;
        auto temp = menu.getListButtons();
        listButtons.insert(listButtons.end(), temp.begin(), temp.end());
        temp = stdProject.getListButtons();
        listButtons.insert(listButtons.end(), temp.begin(), temp.end());
        engineAPI->loadButtons(listButtons);
    }

    if(sceneID == CARDS_HAND_VIEW) {
        auto listButtons = popupHandCards.getListButtons();
        engineAPI->loadButtons(listButtons);
    }
}

void render::Scene::print() {
    cout << " USE COUNT : " << this->popupHandCards.closeButton.use_count() << endl;
}

void render::Scene::handleEvent(sf::Event event) {

    if(event.type == sf::Event::MouseButtonPressed){
        engineAPI->onClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), *this);
    }
    else if(event.type == sf::Event::MouseMoved) {
        engineAPI->onMouseMoved(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
}
