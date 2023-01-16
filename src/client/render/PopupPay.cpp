#include "PopupPay.h"
#include <iostream>

using namespace std;
using namespace render;

float buttonOffset = 50;
float ressourceOffset = 100;

sf::Vector2f vminusButton = {900, 400};
sf::Vector2f vplusButton = {vminusButton.x+buttonOffset, vminusButton.y};
sf::Vector2f vgoldImage = {vminusButton.x + buttonOffset/2, vminusButton.y - 10};
sf::Vector2f vcardImage = {50,50};

render::PopupPay::PopupPay() {
    sf::Vector2f vbackground = {0, 0};
    sf::Vector2f vcloseButton = {900, 850};
    sf::Vector2f vpayButton = {700, 850};
    this->background = make_shared<Image>("popupFrame.png", vbackground);
    this->listComponents.push_back(this->background);

    //Close Button
    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->closeButton->setScale(0.3f);
    this->closeButton->updateClickableArea();
    this->closeButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        sharedContext->getSceneManager()->removeScene();
    });
    this->listComponents.push_back(this->closeButton);
    this->listButtons.push_back(this->closeButton);
    //Pay Button
    this->payButton = make_shared<Button>("payButton.png", vpayButton);
    this->payButton->setScale(0.3f);
    this->payButton->updateClickableArea();
    this->payButton->setFunctionStr("Pay Card Cost");
    this->listComponents.push_back(this->payButton);
    this->listButtons.push_back(this->payButton);

    //Minus Button
    this->minusButton = make_shared<Button>("minusButton.png", vminusButton);
    this->minusButton->setScale(0.3f);
    this->minusButton->updateClickableArea();
    this->minusButton->setFunctionStr("Reduce Ressource Cost");
    this->listComponents.push_back(this->minusButton);
    this->listButtons.push_back(this->minusButton);

    //Plus Button
    this->plusButton = make_shared<Button>("plusButton.png", vplusButton);
    this->plusButton->setScale(0.3f);
    this->plusButton->updateClickableArea();
    this->plusButton->setFunctionStr("Increase Ressource Cost");
    this->listComponents.push_back(this->plusButton);
    this->listButtons.push_back(this->plusButton);

    //Gold Image
    this->goldImage = make_shared<Image>("megacredit.png", vgoldImage);
    this->listComponents.push_back(this->goldImage);
}

render::PopupPay::~PopupPay() = default;

void render::PopupPay::update(const std::unordered_map<std::string, std::string> &data) {

    float ratio = 0.55f;
    bool space, building;
    string filename;
    filename = "card_" + data.at("idCard") + ".png";
    this->cardImage = make_shared<Image>(filename, vcardImage);
}

void render::PopupPay::draw(sf::RenderWindow &window) {
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}

std::vector<std::shared_ptr<Button>> render::PopupPay::getListButtons() {
    return listButtons;
}