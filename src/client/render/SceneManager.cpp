#include "SceneManager.h"
#include <iostream>

#include <utility>
#include <iostream>

using namespace std;
using namespace render;

// This technique prevents the double call of the constructor of each class
render::SceneManager::SceneManager(){
    titleScene = make_shared<TitleScene>();
    optionScene = make_shared<OptionScene>();
    mainScene = make_shared<MainScene>();
    cardScene = make_shared<CardScene>(false);
    blueCardScene = make_shared<CardScene>(true);
    badgeScene = make_shared<BadgeScene>();
    payScene = make_shared<PayScene>();
    placeTileScene = make_shared<PlaceTileScene>();


    eventHandler = make_shared<EventHandler>();
    dataProvider = make_shared<state::RenderAPI>();

    sceneMap.insert({SceneID::TITLE_VIEW, titleScene});
    sceneMap.insert({SceneID::OPTION_VIEW, optionScene});
    sceneMap.insert({SceneID::CARDS_VIEW, cardScene});
    sceneMap.insert({SceneID::BLUE_CARD_VIEW, blueCardScene});
    sceneMap.insert({SceneID::BOARD_VIEW, mainScene});
    sceneMap.insert({SceneID::BADGE_VIEW, badgeScene});
    sceneMap.insert({SceneID::PAY_VIEW, payScene});
}

render::SceneManager::~SceneManager() {

}

void render::SceneManager::draw(sf::RenderWindow& window) {

    if(displayedSceneStack.empty()) {
        cout << "Empty Scene !" << endl;
        exit(1);
    }
    // Gets the index of the first scene that is non-transparent on the stack
    size_t index = displayedSceneStack.size() - 1;
    while(index != 0) {
        if(!displayedSceneStack[index]->getTransparent()) {
            break;
        }
        index--;
    }
    int firstNonTransparent = (int)index;

    // Displays in order from the first non-transparent scene
    for (int i = firstNonTransparent; i < displayedSceneStack.size(); i++) {
        displayedSceneStack[i]->draw(window);
    }
}

void render::SceneManager::update() {

    /*cout << "----------- NEW DATA -------------" << endl;

    for (const auto &dataEl: data) {
        cout << "{ First : " << dataEl.first << "; Second : " << dataEl.second << " }" << endl;
    }*/
    // ------------------------------------- TITLE VIEW -----------------------------------
    if(currentScene == TITLE_VIEW){

    }

    // ------------------------------------- OPTION VIEW -----------------------------------
    if(currentScene == OPTION_VIEW){

    }

    if(currentScene == BOARD_VIEW) {
        // Board data
        auto playerData = dataProvider->providePlayerData(-1);
        auto mainSceneData = dataProvider->provideMainSceneData();
        mainSceneData.insert(playerData.begin(), playerData.end());


        mainScene->update(mainSceneData);
    }

    if(currentScene == CARDS_VIEW) {
        auto playerData = dataProvider->providePlayerData(-1);

        cardScene->update(playerData);
    }

    if(currentScene == PLACE_TILE_VIEW) {
        auto boardData = dataProvider->provideBoardData();

        placeTileScene->update(boardData);
    }

    if(currentScene == PAY_VIEW) {
        auto playerData = dataProvider->providePlayerData(-1);

        payScene->update(playerData);
    }

    if(currentScene == BADGE_VIEW){
        auto playerData = dataProvider->providePlayerData(-1);

        badgeScene->update(playerData);
    }

    if(currentScene == BLUE_CARD_VIEW){
        auto playerData = dataProvider->providePlayerData(-1);

        blueCardScene->update(playerData);
    }
}

void render::SceneManager::hookData(std::shared_ptr<state::RenderAPI> dataProvider) {
    this->dataProvider = std::move(dataProvider);
}

void render::SceneManager::handleEvent(sf::Event event) {
    eventHandler->handleEvent(event);
    if (currentScene == PLACE_TILE_VIEW) {

    }
}

// Adds a scene on top of the previous one, and loads the buttons
void render::SceneManager::addScene(render::SceneID sceneID) {
    displayedSceneStack.push_back(sceneMap[sceneID]);
    sceneIdStack.push_back(sceneID);

    this->currentScene = sceneIdStack.back();
    this->update();

    eventHandler->loadButtons(displayedSceneStack.back()->getListButtons());
}

// Removes the top scene
void render::SceneManager::removeScene() {
    displayedSceneStack.pop_back();
    sceneIdStack.pop_back();
    currentScene = sceneIdStack.back();

    this->currentScene = sceneIdStack.back();
    this->update();

    eventHandler->loadButtons(displayedSceneStack.back()->getListButtons());
}

// Goes back to the main scene
void render::SceneManager::displayMainScene() {
    displayedSceneStack.clear();
    displayedSceneStack.push_back(mainScene);
}

const shared_ptr<EventHandler> &render::SceneManager::getEventHandler() const {
    return eventHandler;
}

const std::shared_ptr<PayScene>& render::SceneManager::getPayScene() const {
    return this->payScene;
}


