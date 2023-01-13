#include "SceneManager.h"
#include <iostream>

#include <utility>
#include <iostream>

using namespace std;

// This technique prevents the double call of the constructor of each class
render::SceneManager::SceneManager(){
    mainScene = make_shared<MainScene>();
    cardScene = make_shared<CardScene>();
    engineAPI = make_shared<EngineAPI>();
    dataProvider = make_shared<state::RenderAPI>();

    sceneMap.insert({SceneID::CARDS_VIEW, cardScene});
    sceneMap.insert({SceneID::BOARD_VIEW, mainScene});
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

    // ------------------------------------- BOARD VIEW -----------------------------------
    if(currentScene == BOARD_VIEW) {
        // Board data
        auto playerData = dataProvider->providePlayerData(0);

        unordered_map<string, string> mainSceneData = dataProvider->provideMainSceneData();

        mainSceneData.insert(playerData.begin(), playerData.end());

        mainScene->update(mainSceneData);
    }

    // -------------------------------------- CARDS HAND VIEW -----------------------------------
    if(currentScene == CARDS_VIEW) {
        auto playerData = dataProvider->providePlayerData(0);

        cardScene->update(playerData);
    }
}

void render::SceneManager::hookData(std::shared_ptr<state::RenderAPI> dataProvider) {
    this->dataProvider = dataProvider;
}

void render::SceneManager::handleEvent(sf::Event event) {

    if(event.type == sf::Event::MouseButtonPressed){
        engineAPI->onClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), *this);
    }
    else if(event.type == sf::Event::MouseMoved) {
        engineAPI->onMouseMoved(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
}

// Adds a scene on top of the previous one
void render::SceneManager::addScene(render::SceneID sceneID) {
    displayedSceneStack.push_back(sceneMap[sceneID]);
    sceneIdStack.push_back(sceneID);

    this->currentScene = sceneIdStack.back();
    this->update();

    engineAPI->loadButtons(displayedSceneStack.back()->getListButtons());
}

// Removes the top scene
void render::SceneManager::removeScene() {
    displayedSceneStack.pop_back();
    sceneIdStack.pop_back();
    currentScene = sceneIdStack.back();

    this->currentScene = sceneIdStack.back();
    this->update();

    engineAPI->loadButtons(displayedSceneStack.back()->getListButtons());
}

// Goes back to the main scene
void render::SceneManager::displayMainScene() {
    displayedSceneStack.clear();
    displayedSceneStack.push_back(mainScene);
}


