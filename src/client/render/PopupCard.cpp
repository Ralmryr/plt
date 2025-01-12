#include "PopupCard.h"
#include <iostream>

using namespace std;
using namespace render;

render::PopupCard::PopupCard(bool blueCard) {
    this->blueCard = blueCard;
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


render::PopupCard::~PopupCard() = default;

void render::PopupCard::update(const std::unordered_map<std::string, std::string>& data) {
    if(data.size() == listComponents.size() - 2) return;

    listButtons.clear();
    listButtons.push_back(closeButton);
    listComponents.clear();
    listComponents.push_back(background);
    listComponents.push_back(closeButton);

/*    cout << "----------- NEW DATA -------------" << endl;

    for (const auto &dataEl: data) {
        cout << "{ First : " << dataEl.first << "; Second : " << dataEl.second << " }" << endl;
    }*/

    //------BLUE CARDS---------
    if(blueCard){
        int i = 0;
        int cardsPerRow = 8;
        sf::Vector2f offset = {60, 50};
        sf::Vector2f cardSpacing = {230, 270};
        float ratio = 0.75f;
        string filename;
        for(const auto& card : data) {
            auto cardData = card.second;
            int idCard = stoi(card.first);

            filename = "card_" + to_string(idCard) + ".png";
            float x = cardSpacing.x * (i % cardsPerRow);
            float y = cardSpacing.y * (i / cardsPerRow);

            auto newCard = make_shared<Button>("cards/" + filename, sf::Vector2f(x, y) + offset);
            newCard->setScale(ratio);
            newCard->setOnClickFunction([idCard](const shared_ptr<SharedContext> &sharedContext) {
                sharedContext->getSceneManager()->getPayScene()->setCardId(idCard);
                sharedContext->getSceneManager()->removeScene();
                sharedContext->getSceneManager()->addScene(PAY_VIEW);
                cout << "Card clicked, ID : " << idCard << endl;
            });

            listButtons.push_back(newCard);
            listComponents.push_back(std::move(newCard));
            i++;
        }
    }
        //------NORMAL CARDS---------
    else{
        int i = 0;
        int cardsPerRow = 8;
        sf::Vector2f offset = {60, 50};
        sf::Vector2f cardSpacing = {230, 270};
        float ratio = 0.75f;
        string filename;
        for(const auto& card : data) {
            auto cardData = card.second;
            int idCard = stoi(card.first);

            filename = "card_" + card.first + ".png";
            float x = cardSpacing.x * (i%cardsPerRow);
            float y = cardSpacing.y * (i/cardsPerRow);

            auto newCard = make_shared<Button>("cards/" + filename, sf::Vector2f(x, y) + offset);
            newCard->setScale(ratio);
            newCard->setOnClickFunction([idCard](const shared_ptr<SharedContext>& sharedContext) {
                sharedContext->getSceneManager()->getPayScene()->setCardId(idCard);
                sharedContext->getSceneManager()->removeScene();
                sharedContext->getSceneManager()->addScene(PAY_VIEW);
                cout << "Card clicked, ID : " << idCard << endl;
            });
            listButtons.push_back(newCard);
            listComponents.push_back(std::move(newCard));
            i++;
        }
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
