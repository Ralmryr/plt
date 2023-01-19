#include "OptionScene.h"

using namespace render;
using namespace std;


OptionScene::OptionScene() {
    transparent = true;
    int textSize = 40;
    sf::Vector2f offset = {200,230};
    sf::Vector2f textOffset = {125,15};

    sf::Vector2f vbackground = {0,0};
    sf::Vector2f vconfirmButton = {900,900};
    sf::Vector2f vplayerMinusButton = {850,300};;
    sf::Vector2f vplayerPlusButton = {vplayerMinusButton.x + offset.x,vplayerMinusButton.y};;
    sf::Vector2f viaEasyMinusButton = {vplayerMinusButton.x,vplayerMinusButton.y+offset.y};;
    sf::Vector2f viaEasyPlusButton = {vplayerMinusButton.x+offset.x,viaEasyMinusButton.y};;
    sf::Vector2f viaNormalMinusButton = {vplayerMinusButton.x,viaEasyMinusButton.y+offset.y};;
    sf::Vector2f viaNormalPlusButton = {vplayerMinusButton.x+offset.x,viaNormalMinusButton.y};;
    sf::Vector2f vplayerText = {vplayerMinusButton.x+textOffset.x,vplayerMinusButton.y+textOffset.y};;
    sf::Vector2f viaEasyText = {viaEasyMinusButton.x+textOffset.x,viaEasyMinusButton.y+textOffset.y};;
    sf::Vector2f viaNormalText = {viaNormalMinusButton.x+textOffset.x,viaNormalMinusButton.y+textOffset.y};;


    //Background
    this->background = make_shared<Image>("popupFrameOption.png", vbackground);
    this->listComponents.push_back(this->background);

    //Confirm Button
    this->confirmButton = make_shared<Button>("confirmButton.png", vconfirmButton);
    this->confirmButton->setScale(0.3f);
    this->confirmButton->updateClickableArea();
    this->confirmButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {

        sharedContext->getSceneManager()->removeScene();
    });
    this->listComponents.push_back(this->confirmButton);
    this->listButtons.push_back(this->confirmButton);

    //Player Text
    this->playerText = make_shared<Text>("2",vplayerText);
    this->playerText->setSizeText(textSize);
    this->playerText->setColor(sf::Color::White);
    this->listComponents.push_back(playerText);
    this->listText.push_back(playerText);

    //IA Easy Text
    this->iaEasyText = make_shared<Text>("0",viaEasyText);
    this->iaEasyText->setSizeText(textSize);
    this->iaEasyText->setColor(sf::Color::White);
    this->listComponents.push_back(iaEasyText);
    this->listText.push_back(iaEasyText);

    //IA Normal Text
    this->iaNormalText = make_shared<Text>("0",viaNormalText);
    this->iaNormalText->setSizeText(textSize);
    this->iaNormalText->setColor(sf::Color::White);
    this->listComponents.push_back(iaNormalText);
    this->listText.push_back(iaNormalText);

    //Player minus Button
    this->playerMinusButton = make_shared<Button>("minusButton.png", vplayerMinusButton);
    this->playerMinusButton->setScale(0.4f);
    this->playerMinusButton->updateClickableArea();
    this->playerMinusButton->setOnClickFunction([playerText = this->playerText, iaEasyText = this->iaEasyText, iaNormalText = this->iaNormalText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(playerText->getText()) > 2) {
            playerText->setText(to_string(stoi(playerText->getText()) - 1));
            if(stoi(playerText->getText()) < stoi(iaEasyText->getText()) + stoi(iaNormalText->getText())){
                if(stoi(iaEasyText->getText()) > 0){
                    iaEasyText->setText(to_string(stoi(iaEasyText->getText()) - 1));
                }
                else if(stoi(iaNormalText->getText()) > 0){
                    iaNormalText->setText(to_string(stoi(iaNormalText->getText()) - 1));
                }
            }
        }
    });
    this->listComponents.push_back(this->playerMinusButton);
    this->listButtons.push_back(this->playerMinusButton);

    //Player plus Button
    this->playerPlusButton = make_shared<Button>("plusButton.png", vplayerPlusButton);
    this->playerPlusButton->setScale(0.4f);
    this->playerPlusButton->updateClickableArea();
    this->playerPlusButton->setOnClickFunction([playerText = this->playerText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(playerText->getText()) < 5) {
            playerText->setText(to_string(stoi(playerText->getText()) + 1));
        }
    });
    this->listComponents.push_back(this->playerPlusButton);
    this->listButtons.push_back(this->playerPlusButton);

    //IA Easy minus Button
    this->iaEasyMinusButton = make_shared<Button>("minusButton.png", viaEasyMinusButton);
    this->iaEasyMinusButton->setScale(0.4f);
    this->iaEasyMinusButton->updateClickableArea();
    this->iaEasyMinusButton->setOnClickFunction([iaEasyText = this->iaEasyText, playerText = this->playerText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(iaEasyText->getText()) >0) {
            iaEasyText->setText(to_string(stoi(iaEasyText->getText()) - 1));
        }
    });
    this->listComponents.push_back(this->iaEasyMinusButton);
    this->listButtons.push_back(this->iaEasyMinusButton);

    //IA Easy plus Button
    this->iaEasyPlusButton = make_shared<Button>("plusButton.png", viaEasyPlusButton);
    this->iaEasyPlusButton->setScale(0.4f);
    this->iaEasyPlusButton->updateClickableArea();
    this->iaEasyPlusButton->setOnClickFunction([iaEasyText = this->iaEasyText, iaNormalText = this->iaNormalText,playerText = this->playerText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(iaEasyText->getText()) < stoi(playerText->getText())-stoi(iaNormalText->getText())) {
            iaEasyText->setText(to_string(stoi(iaEasyText->getText()) + 1));
        }
    });
    this->listComponents.push_back(this->iaEasyPlusButton);
    this->listButtons.push_back(this->iaEasyPlusButton);

    //IA Normal minus Button
    this->iaNormalMinusButton = make_shared<Button>("minusButton.png", viaNormalMinusButton);
    this->iaNormalMinusButton->setScale(0.4f);
    this->iaNormalMinusButton->updateClickableArea();
    this->iaNormalMinusButton->setOnClickFunction([iaNormalText = this->iaNormalText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(iaNormalText->getText()) >0) {
            iaNormalText->setText(to_string(stoi(iaNormalText->getText()) - 1));
        }
    });
    this->listComponents.push_back(this->iaNormalMinusButton);
    this->listButtons.push_back(this->iaNormalMinusButton);

    //IA Normal plus Button
    this->iaNormalPlusButton = make_shared<Button>("plusButton.png", viaNormalPlusButton);
    this->iaNormalPlusButton->setScale(0.4f);
    this->iaNormalPlusButton->updateClickableArea();
    this->iaNormalPlusButton->setOnClickFunction([iaNormalText = this->iaNormalText, iaEasyText = this->iaEasyText, playerText = this->playerText](const shared_ptr<SharedContext>& sharedContext) {
        if(stoi(iaNormalText->getText()) < stoi(playerText->getText())-stoi(iaEasyText->getText())) {
            iaNormalText->setText(to_string(stoi(iaNormalText->getText()) + 1));
        }
    });
    this->listComponents.push_back(this->iaNormalPlusButton);
    this->listButtons.push_back(this->iaNormalPlusButton);


}

OptionScene::~OptionScene() = default;

void OptionScene::draw(sf::RenderWindow &window) {
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}

void OptionScene::update(const std::unordered_map<std::string, std::string> &data) {

}

vector<shared_ptr<Button>> OptionScene::getListButtons() {
    return this->listButtons;
}