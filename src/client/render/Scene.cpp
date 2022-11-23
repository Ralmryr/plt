#include "Scene.h"

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
    /*popupBadge.update();
    popupBlueCards.update();
    popupHandCards.update();
    playerScoreDisplay.update();
    globalParametersDisplay.update();
    boardDisplay.update();
    menu.update();*/

}
