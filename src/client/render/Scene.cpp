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
    //popupBadge.draw(window);
    //popupBlueCards.draw(window);
    //popupHandCards.draw(window);
    globalParametersDisplay.draw(window);
    stdProject.draw(window);
    playerScoreDisplay.draw(window);
    menu.draw(window);
}

void render::Scene::update() {
    auto data = dataProvider->providePlayerData(3);
    cout << "---------- NEW DATA ----------------" << endl;
    for(const auto& dataEl : data) {
        cout << "{ First : " << dataEl.first << ", Second : " << dataEl.second << " }"<< endl;
    }
    /*popupBadge.update();
    popupBlueCards.update();
    popupHandCards.update();
    playerScoreDisplay.update();
    globalParametersDisplay.update();
    boardDisplay.update();
    menu.update();*/

}

void render::Scene::hookData(std::shared_ptr<state::UiDataProvider> dataProvider) {
    this->dataProvider = dataProvider;
}
