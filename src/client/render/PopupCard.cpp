#include "PopupCard.h"
#include <iostream>

using namespace std;
using namespace render;

render::PopupCard::PopupCard() {
    sf::Vector2f vbackground = {0, 0};
    sf::Vector2f vcloseButton = {900, 850};
    this->background = make_shared<Image>("popupFrame.png", vbackground);

    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->closeButton->setScale(0.8f);
    this->closeButton->updateClickableArea();
    closeButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        sharedContext->getSceneManager()->removeScene();
    });

    this->listComponents.push_back(this->background);
    this->listComponents.push_back(this->closeButton);

    this->listButtons.push_back(closeButton);
}

render::PopupCard::~PopupCard() {

}

void render::PopupCard::update(const std::unordered_map<std::string, std::string>& data) {

/*        cout << "----------- NEW DATA -------------" << endl;

    for (const auto &dataEl: data) {
        cout << "{ First : " << dataEl.first << "; Second : " << dataEl.second << " }" << endl;
    }*/

    if(data.size() <= listComponents.size() - 2) return;
    int i = 0;
    int cardsPerRow = 8;
    sf::Vector2f offset = {60, 50};
    sf::Vector2f cardSpacing = {230, 270};
    float ratio = 0.55f;
    string filename;
    for(const auto& card : data) {
        filename = "card_"+ to_string(i+1) + ".png";
        float x = cardSpacing.x * (i%cardsPerRow);
        float y = cardSpacing.y * (i/cardsPerRow);
        auto newCard = make_shared<Button>("cards/" + filename, sf::Vector2f(x, y) + offset);
        newCard->setScale(ratio);
        newCard->setOnClickFunction([i](const shared_ptr<SharedContext>& sharedContext) {
            sharedContext->getSceneManager()->getPayScene()->setCardId(i+1);
            sharedContext->getSceneManager()->removeScene();
            sharedContext->getSceneManager()->addScene(PAY_VIEW);
        });
        listButtons.push_back(newCard);
        listComponents.push_back(std::move(newCard));
        i++;
    }
}

void render::PopupCard::draw(sf::RenderWindow& window) {
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}

vector<std::shared_ptr<Button>> render::PopupCard::getListButtons() {
    return this->listButtons;
}
