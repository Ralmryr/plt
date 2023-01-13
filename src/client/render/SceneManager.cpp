#include "SceneManager.h"
#include <iostream>

#include <utility>
#include <iostream>

using namespace std;

// This technique prevents the double call of the constructor of each class
render::SceneManager::SceneManager() : mainScene(), cardScene(){
    engineAPI = make_shared<EngineAPI>();
    dataProvider = make_shared<state::RenderAPI>();
}

render::SceneManager::~SceneManager() {

}

void render::SceneManager::draw(sf::RenderWindow& window) {
    if (currentScene == CARDS_VIEW || currentScene == BOARD_VIEW || currentScene == BADGE_VIEW) {
        mainScene.draw(window);

    }
    if(currentScene == CARDS_VIEW) {
        cardScene.draw(window);
    }
}

void render::SceneManager::update() {

    // ------------------------------------- BOARD VIEW -----------------------------------
    if(currentScene == BOARD_VIEW) {
        // Board data
        auto playerData = dataProvider->providePlayerData(0);

        unordered_map<string, string> mainSceneData = dataProvider->provideMainSceneData();

        mainSceneData.insert(playerData.begin(), playerData.end());

        mainScene.update(mainSceneData);


    }


    // -------------------------------------- CARDS HAND VIEW -----------------------------------
    if(currentScene == CARDS_VIEW) {
        auto playerData = dataProvider->providePlayerData(0);

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
        cardScene.update(cardsHandData);
    }
}

void render::SceneManager::hookData(std::shared_ptr<state::RenderAPI> dataProvider) {
    this->dataProvider = dataProvider;
}

void render::SceneManager::setScene(render::SceneID sceneID) {
    this->currentScene = sceneID;
    this->update();

   /* if(sceneID == BOARD_VIEW){
        vector<shared_ptr<Button>> listButtons;
        auto temp = menu.getListButtons();
        listButtons.insert(listButtons.end(), temp.begin(), temp.end());
        temp = stdProject.getListButtons();
        listButtons.insert(listButtons.end(), temp.begin(), temp.end());
        engineAPI->loadButtons(listButtons);
    }

    if(sceneID == CARDS_VIEW) {
        auto listButtons = popupHandCards.getListButtons();
        engineAPI->loadButtons(listButtons);
    } */
}

void render::SceneManager::print() {
    //cout << " USE COUNT : " << this->popupHandCards.closeButton.use_count() << endl;
}

void render::SceneManager::handleEvent(sf::Event event) {

    if(event.type == sf::Event::MouseButtonPressed){
        engineAPI->onClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), *this);
    }
    else if(event.type == sf::Event::MouseMoved) {
        engineAPI->onMouseMoved(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
}


