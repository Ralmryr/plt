#include "PopupPay.h"
#include <iostream>

using namespace std;
using namespace render;
using namespace state;


sf::Vector2f vcardImage = {330,315};

render::PopupPay::PopupPay() {
    this->opened = false;
    this->cardSize={331,441};
    float buttonOffset = 195;
    float buttonSize = 100;
    float ressourceoffset = buttonSize + 50;
    float textoffset = 20;
    int textSize = 40;

    sf::Vector2f vminusButton = {705, 490};
    sf::Vector2f vplusButton = {vminusButton.x+buttonOffset, vminusButton.y};
    sf::Vector2f vgoldImage = {vminusButton.x + buttonOffset/2 + buttonSize/4, vminusButton.y - buttonOffset/2};
    sf::Vector2f vbackground = {0, 0};
    sf::Vector2f vcloseButton = {900, 850};
    sf::Vector2f vpayButton = {vcardImage.x, vcardImage.y+cardSize.y+20};

    sf::Vector2f vminusButtonSpace = {vplusButton.x+ressourceoffset, vminusButton.y};
    sf::Vector2f vplusButtonSpace = {vminusButtonSpace.x+buttonOffset, vplusButton.y};
    sf::Vector2f vtitaniumImage = {vminusButtonSpace.x + buttonOffset/2 + buttonSize/4, vminusButton.y - buttonOffset/2};
    sf::Vector2f vminusButtonBuilding = {vplusButtonSpace.x+ressourceoffset, vminusButton.y};
    sf::Vector2f vplusButtonBuilding = {vminusButtonBuilding.x+buttonOffset, vplusButton.y};
    sf::Vector2f vironImage = {vminusButtonBuilding.x + buttonOffset/2 + buttonSize/4, vplusButton.y - buttonOffset/2};

    sf::Vector2f vgoldTotal = {vgoldImage.x+14,vminusButton.y+textoffset};
    sf::Vector2f vironTotal = {vironImage.x+14,vminusButtonBuilding.y+textoffset};
    sf::Vector2f vtitaniumTotal = {vtitaniumImage.x+14,vminusButtonSpace.y+textoffset};
    sf::Vector2f vtotal = {vpayButton.x+250,vpayButton.y+30};

    this->cardId = -1;

    this->background = make_shared<Image>("popupFrame.png", vbackground);
    this->listBaseComponents.push_back(this->background);

    //Gold Total
    this->goldTotal = make_shared<Text>("0",vgoldTotal);
    this->goldTotal->setSizeText(textSize);
    this->goldTotal->setColor(sf::Color::White);
    this->listBaseComponents.push_back(goldTotal);
    this->listText.push_back(goldTotal);

    //Iron Total
    this->ironTotal = make_shared<Text>("0",vironTotal);
    this->ironTotal->setSizeText(textSize);
    this->ironTotal->setColor(sf::Color::White);

    //Titanium Total
    this->titaniumTotal = make_shared<Text>("0",vtitaniumTotal);
    this->titaniumTotal->setSizeText(textSize);
    this->titaniumTotal->setColor(sf::Color::White);

    //Total
    this->total = make_shared<Text>("0",vtotal);
    this->total->setSizeText(textSize+15);
    this->total->setColor(sf::Color::Red);
    this->listBaseComponents.push_back(total);
    this->listText.push_back(total);

    //Pay Button
    this->payButton = make_shared<Button>("payButton.png", vpayButton);
    this->payButton->setScale(0.3f);
    this->payButton->updateClickableArea();
    this->payButton->setFunctionStr("Pay Card Cost");
    this->listBaseComponents.push_back(this->payButton);
    this->listButtons.push_back(this->payButton);

    //Minus Button
    this->minusButton = make_shared<Button>("minusButton.png", vminusButton);
    this->minusButton->setScale(0.5f);
    this->minusButton->updateClickableArea();
    this->minusButton->setFunctionStr("Reduce Ressource Cost");
    this->listBaseComponents.push_back(this->minusButton);
    this->listButtons.push_back(this->minusButton);


    //Plus Button
    this->plusButton = make_shared<Button>("plusButton.png", vplusButton);
    this->plusButton->setScale(0.5f);
    this->plusButton->updateClickableArea();
    this->listBaseComponents.push_back(this->plusButton);
    this->listButtons.push_back(this->plusButton);

    //Minus Button Space
    this->minusButtonSpace = make_shared<Button>("minusButton.png", vminusButtonSpace);
    this->minusButtonSpace->setScale(0.5f);
    this->minusButtonSpace->updateClickableArea();
    this->minusButtonSpace->setFunctionStr("Reduce Ressource Cost");

    //Plus Button Space
    this->plusButtonSpace = make_shared<Button>("plusButton.png", vplusButtonSpace);
    this->plusButtonSpace->setScale(0.5f);
    this->plusButtonSpace->updateClickableArea();
    this->plusButtonSpace->setFunctionStr("Increase Ressource Cost");

    //Minus Button Building
    this->minusButtonBuilding = make_shared<Button>("minusButton.png", vminusButtonBuilding);
    this->minusButtonBuilding->setScale(0.5f);
    this->minusButtonBuilding->updateClickableArea();
    this->minusButtonBuilding->setFunctionStr("Reduce Ressource Cost");

    //Plus Button Building
    this->plusButtonBuilding = make_shared<Button>("plusButton.png", vplusButtonBuilding);
    this->plusButtonBuilding->setScale(0.5f);
    this->plusButtonBuilding->updateClickableArea();
    this->plusButtonBuilding->setFunctionStr("Increase Ressource Cost");

    //Gold Image
    this->goldImage = make_shared<Image>("megacredit.png", vgoldImage);
    this->goldImage->setScale(0.1f);
    this->listBaseComponents.push_back(this->goldImage);

    //Titanium Image
    this->titaniumImage = make_shared<Image>("titanium.png", vtitaniumImage);
    this->titaniumImage->setScale(0.17f);

    //Iron Image
    this->ironImage = make_shared<Image>("steel.png", vironImage);
    this->ironImage->setScale(0.17f);

    //Close Button
    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->closeButton->setScale(0.8f);
    this->closeButton->updateClickableArea();
    this->closeButton->setOnClickFunction([listComponents = &listComponents, opened = &opened, listText = &listText, total = total](const shared_ptr<SharedContext>& sharedContext) {
        *opened = false;
        for(const auto& text : *listText)
            text->setText(to_string(0));
        total->setColor(sf::Color::Red);
        listComponents->clear();
        sharedContext->getSceneManager()->removeScene();
    });
    this->listBaseComponents.push_back(this->closeButton);
    this->listButtons.push_back(this->closeButton);

}

render::PopupPay::~PopupPay() = default;

void render::PopupPay::update(const std::unordered_map<std::string, std::string> &data) {
    // Code that needs to be executed only once
    if(opened) return;
    opened = true;

    // "cost,badge1,badge2,...,badgeN"
    string cardData = data.at(to_string(cardId));

    int cost;
    bool space = false, building = false;

    // Parse cost from cardData and removes it
    size_t pos = cardData.find(',');
    cost = stoi(cardData.substr(0, pos));
    cardData.erase(0, pos + 1); // "badge1,badge2,...,badge"

    // Parse badges from cardData and removes them
    while ((pos = cardData.find(',')) != std::string::npos) {
        int badgeNumber = stoi(cardData.substr(0, pos));
        if(badgeNumber == Badge::BUILDING)
            building = true;
        if(badgeNumber == Badge::SPACE)
            space = true;
        cardData.erase(0, pos + 1);
    }

    string filename;
    filename = "card_" + to_string(cardId) + ".png";
    this->cardImage = make_shared<Image>("cards/" + filename, vcardImage);

    auto updateTextFct = [total = total, cost](Text &text, int amount, int resValue, int max = 999) {
        int newResourceAmount = stoi(text.getText()) + amount;
        int newTotalValue = stoi(total->getText()) + amount*resValue;
        if(newResourceAmount <= max && newResourceAmount >= 0) {
            text.setText(to_string(newResourceAmount));
            total->setText(to_string(newTotalValue));
        }

        if(newTotalValue >= cost)
            total->setColor(sf::Color::Green);
        else
            total->setColor(sf::Color::Red);
    };

    int GOLD_VALUE = 1;
    int IRON_VALUE = 2;
    int TITANIUM_VALUE = 3;

    //Setting Plus and minus for Gold
    this->plusButton->setOnClickFunction([goldTotal = goldTotal, total = total, updateTextFct, cost, data, GOLD_VALUE](const shared_ptr<SharedContext>& sharedContext) {
        bool enoughToPayCard = stoi(total->getText()) >= cost;
        int playerGold = stoi(data.at("resource " + to_string(GOLD)));

        if(!enoughToPayCard) {
            updateTextFct(*goldTotal, 1, GOLD_VALUE, playerGold);
        }
    });
    this->minusButton->setOnClickFunction([goldTotal = goldTotal, total = total, updateTextFct, GOLD_VALUE](const shared_ptr<SharedContext>& sharedContext) {
        updateTextFct(*goldTotal, -1, GOLD_VALUE);
    });

    // If the card has a space badge, the player is able to pay with titanium
    if (space){
        //Adding Buttons
        this->listComponents.push_back(minusButtonSpace);
        this->listButtons.push_back(minusButtonSpace);
        this->listComponents.push_back(plusButtonSpace);
        this->listButtons.push_back(plusButtonSpace);

        //Adding Image
        this->listComponents.push_back(titaniumImage);

        //Adding Texts
        this->listComponents.push_back(titaniumTotal);
        this->listText.push_back(titaniumTotal);

        //Setting Plus and minus function
        this->plusButtonSpace->setOnClickFunction([titaniumTotal = titaniumTotal, total = total, updateTextFct, cost, data, TITANIUM_VALUE](const shared_ptr<SharedContext>& sharedContext) {
            bool enoughToPayCard = stoi(total->getText()) >= cost;
            int playerTitanium = stoi(data.at("resource " + to_string(GOLD)));

            if(!enoughToPayCard) {
                updateTextFct(*titaniumTotal, 1, TITANIUM_VALUE, playerTitanium);
            }
        });
        this->minusButtonSpace->setOnClickFunction([titaniumTotal = titaniumTotal, total = total, updateTextFct, TITANIUM_VALUE](const shared_ptr<SharedContext>& sharedContext) {
            updateTextFct(*titaniumTotal, -1, TITANIUM_VALUE);
        });

    }

    // If the card has a building badge, the player is able to pay with iron
    if (building){
        //Adding Buttons
        this->listComponents.push_back(minusButtonBuilding);
        this->listButtons.push_back(minusButtonBuilding);
        this->listComponents.push_back(plusButtonBuilding);
        this->listButtons.push_back(plusButtonBuilding);

        //Adding Image
        this->listComponents.push_back(ironImage);

        //Adding Texts
        this->listComponents.push_back(ironTotal);
        this->listText.push_back(ironTotal);

        //Setting Plus and minus function
        this->plusButtonBuilding->setOnClickFunction([ironTotal = ironTotal, total = total, updateTextFct, cost, data, IRON_VALUE](const shared_ptr<SharedContext>& sharedContext) {
            bool enoughToPayCard = stoi(total->getText()) >= cost;
            int playerIron = stoi(data.at("resource " + to_string(GOLD)));

            if(!enoughToPayCard) {
                updateTextFct(*ironTotal, 1, IRON_VALUE, playerIron);
            }
        });
        this->minusButtonBuilding->setOnClickFunction([ironTotal = ironTotal, total = total, updateTextFct, IRON_VALUE](const shared_ptr<SharedContext>& sharedContext) {
            updateTextFct(*ironTotal, -1, IRON_VALUE);
        });
    }

    auto payButtonFunction = [cardId = cardId, closeButton = closeButton, total = total, cost](const shared_ptr<SharedContext>& sharedContext) {
        bool enoughToPayCard = stoi(total->getText()) >= cost;
        if(enoughToPayCard) {
            engine::EventDetails eventDetails(engine::CARD_PLAYED);
            eventDetails["idCardPlayed"] = cardId;
            sharedContext->getEventManager()->notify(eventDetails);
            closeButton->onClick(sharedContext);
        }
    };
    this->payButton->setOnClickFunction(payButtonFunction);

    this->listComponents.push_back(this->cardImage);
}

void render::PopupPay::draw(sf::RenderWindow &window) {
    for(const auto& component : listBaseComponents) {
        window.draw(*component);
    }
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}

std::vector<std::shared_ptr<Button>> render::PopupPay::getListButtons() {
    return listButtons;
}

void render::PopupPay::setCardId(int cardId) {
    this->cardId = cardId;
}

int render::PopupPay::getCardId() const {
    return this->cardId;
}