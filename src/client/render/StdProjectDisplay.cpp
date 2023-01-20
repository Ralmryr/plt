#include "StdProjectDisplay.h"
#include <iostream>

using namespace render;
using namespace std;

StdProjectDisplay::StdProjectDisplay() {
    //frameImage
    sf::Vector2f posFrameImage = {0, 450};
    this->frameImage = make_shared<Image>("stdProjectFrameImage.png",posFrameImage);
    listComponents.push_back(frameImage);

    //discardButton
    sf::Vector2f posDiscardButton = {30, 460};
    this->discardButton=make_shared<Button>("card.png",posDiscardButton);
    this->discardButton->setScale(0.1f);
    this->discardButton->updateClickableArea();
    this->discardButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 162;

        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(discardButton);
    listButtons.push_back(discardButton);

    //prodEnergyButton
    sf::Vector2f posProdEnergyButton = {25, 525};
    this->prodEnergyButton=make_shared<Button>("megacredit.png",posProdEnergyButton);
    this->prodEnergyButton->setScale(0.09f);
    this->prodEnergyButton->updateClickableArea();
    this->prodEnergyButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 162;
        eventDetails["GoldAmount"] = 11;
        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(prodEnergyButton);
    listButtons.push_back(prodEnergyButton);

    //temperatureButton
    sf::Vector2f posTemperatureButton = {25, 585};
    this->temperatureButton=make_shared<Button>("megacredit.png",posTemperatureButton);
    this->temperatureButton->setScale(0.09f);
    this->temperatureButton->updateClickableArea();
    this->temperatureButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 163;
        eventDetails["GoldAmount"] = 14;
        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(temperatureButton);
    listButtons.push_back(temperatureButton);

    //oceanButton
    sf::Vector2f posOceanButton = {25, 645};
    this->oceanButton=make_shared<Button>("megacredit.png",posOceanButton);
    this->oceanButton->setScale(0.09f);
    this->oceanButton->updateClickableArea();
    this->oceanButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 164;
        eventDetails["GoldAmount"] = 18;
        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(oceanButton);
    listButtons.push_back(oceanButton);

    //forestButton
    sf::Vector2f posForestButton = {25, 705};
    this->forestButton= make_shared<Button>("megacredit.png",posForestButton);
    this->forestButton->setScale(0.09f);
    this->forestButton->updateClickableArea();
    this->forestButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 165;
        eventDetails["GoldAmount"] = 23;
        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(forestButton);
    listButtons.push_back(forestButton);

    //cityButton
    sf::Vector2f posCityButton = {25, 765};
    this->cityButton=make_shared<Button>("megacredit.png",posCityButton);
    this->cityButton->setScale(0.09f);
    this->cityButton->updateClickableArea();
    this->cityButton->setOnClickFunction([](const shared_ptr<SharedContext>& sharedContext) {
        engine::EventDetails eventDetails(engine::CARD_PLAYED);
        eventDetails["idCardPlayed"] = 166;
        eventDetails["GoldAmount"] = 25;
        sharedContext->getEventManager()->notify(eventDetails);
    });
    listComponents.push_back(cityButton);
    listButtons.push_back(cityButton);

    string arrayCost[6] = {"X", "11", "14", "18", "23", "25"};
    for(int i = 0; i < 6; i++) {
        auto newText = make_shared<Text>(arrayCost[i], sf::Vector2f(80, 470 + 60*i));
        newText->setSizeText(30);
        listComponents.push_back(std::move(newText));
    }
}

StdProjectDisplay::~StdProjectDisplay() {}

void StdProjectDisplay::draw(sf::RenderWindow &window) {
    for(const auto &component : this->listComponents){
        window.draw(*component);
    }
}

void StdProjectDisplay::update(const std::unordered_map<std::string,std::string>& data) {
}

std::vector<std::shared_ptr<Button>> StdProjectDisplay::getListButtons() {
    return this->listButtons;
}
