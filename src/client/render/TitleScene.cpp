#include "TitleScene.h"

using namespace render;
using namespace std;


TitleScene::TitleScene() {
    float offset = 100;

    sf::Vector2f vbackground = {0,0};
    sf::Vector2f vplayButton = {750,500};
    sf::Vector2f vquitButton = {1850,0};

    //Background
    this->background = make_shared<Image>("titleScene.png", vbackground);
    this->listComponents.push_back(this->background);

    //Play Button
    this->playButton = make_shared<Button>("playButton.png", vplayButton);
    this->playButton->setScale(0.4f);
    this->playButton->updateClickableArea();
    this->playButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        sharedContext->getSceneManager()->addScene(BOARD_VIEW);
    });
    this->listComponents.push_back(this->playButton);
    this->listButtons.push_back(this->playButton);

    //Quit Button
    this->quitButton = make_shared<Button>("closeButton.png", vquitButton);
    this->quitButton->setScale(0.3f);
    this->quitButton->updateClickableArea();
    this->quitButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        exit(1);
    });
    this->listComponents.push_back(this->quitButton);
    this->listButtons.push_back(this->quitButton);

}

TitleScene::~TitleScene() = default;

void TitleScene::draw(sf::RenderWindow &window) {
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}

void TitleScene::update(const std::unordered_map<std::string, std::string> &data) {

}

vector<shared_ptr<Button>> TitleScene::getListButtons() {
    return this->listButtons;
}
