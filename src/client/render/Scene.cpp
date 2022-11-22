#include "Scene.h"

render::Scene::Scene() {
    this->popupBadge=PopupBadge();
    this->popupBlueCards=PopupBadge(); //to change for PopupCard
    this->popupHandCards=PopupBadge();//to change for PopupCard
    this->playerScoreDisplay=PlayerScoreDisplay();
    this->globalParametersDisplay=GlobalParametersDisplay();
    this->boardDisplay=BoardDisplay();
    this->menu=MenuDisplay();
}

render::Scene::~Scene() {

}

void render::Scene::draw(sf::RenderWindow window) {
    popupBadge.draw(window);
    popupBlueCards.draw(window);
    popupHandCards.draw(window);
    playerScoreDisplay.draw(window);
    globalParametersDisplay.draw(window);
    boardDisplay.draw(window);
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
