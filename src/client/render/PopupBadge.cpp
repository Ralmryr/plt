#include <iostream>
#include "PopupBadge.h"

using namespace render;
using namespace std;

PopupBadge::PopupBadge() {
    opened = false;
    sf::Vector2f offset = {220,185};
    int textSize = 40;

    sf::Vector2f vbackground = {0, 0};
    sf::Vector2f vcloseButton = {900, 900};
    sf::Vector2f vbuildingText = {771, 150};
    sf::Vector2f vscienceText = {vbuildingText.x+offset.x, 150};
    sf::Vector2f vmicrobeText = {vbuildingText.x+2*offset.x, 150};
    sf::Vector2f vjovianText = {771, vbuildingText.y+offset.y};
    sf::Vector2f vanimalText = {vbuildingText.x+offset.x, vbuildingText.y+offset.y};
    sf::Vector2f vvenusText = {vbuildingText.x+2*offset.x, vbuildingText.y+offset.y};
    sf::Vector2f vspaceText = {771, vjovianText.y+offset.y};
    sf::Vector2f vpowerText = {vbuildingText.x+offset.x, vjovianText.y+offset.y};
    sf::Vector2f vplantText = {vbuildingText.x+2*offset.x, vjovianText.y+offset.y};
    sf::Vector2f veventText = {771, vspaceText.y+offset.y};
    sf::Vector2f vearthText = {vbuildingText.x+offset.x, vspaceText.y+offset.y};
    sf::Vector2f vcityText = {vbuildingText.x+2*offset.x, vspaceText.y+offset.y};

    //Background
    this->background = make_shared<Image>("backgroundPopupBadge.png", vbackground);
    this->listComponents.push_back(background);

    //Close Button
    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->closeButton->setScale(0.8f);
    this->closeButton->updateClickableArea();
    this->closeButton->setOnClickFunction([listComponents = &listComponents, opened = &opened](const shared_ptr<SharedContext>& sharedContext) {
        *opened = false;
        listComponents->clear();
        sharedContext->getSceneManager()->removeScene();
    });
    this->listComponents.push_back(closeButton);
    this->listButtons.push_back(closeButton);

    //Texts

    //Building
    this->buildingText = make_shared<Text>("0",vbuildingText);
    this->buildingText->setSizeText(textSize);
    this->buildingText->setColor(sf::Color::White);
    this->listComponents.push_back(buildingText);
    this->listText.push_back(buildingText);

    //Science
    this->scienceText = make_shared<Text>("0",vscienceText);
    this->scienceText->setSizeText(textSize);
    this->scienceText->setColor(sf::Color::White);
    this->listComponents.push_back(scienceText);
    this->listText.push_back(scienceText);

    //Microbe
    this->microbeText = make_shared<Text>("0",vmicrobeText);
    this->microbeText->setSizeText(textSize);
    this->microbeText->setColor(sf::Color::White);
    this->listComponents.push_back(microbeText);
    this->listText.push_back(microbeText);

    //Jovian
    this->jovianText = make_shared<Text>("0",vjovianText);
    this->jovianText->setSizeText(textSize);
    this->jovianText->setColor(sf::Color::White);
    this->listComponents.push_back(jovianText);
    this->listText.push_back(jovianText);

    //Animal
    this->animalText = make_shared<Text>("0",vanimalText);
    this->animalText->setSizeText(textSize);
    this->animalText->setColor(sf::Color::White);
    this->listComponents.push_back(animalText);
    this->listText.push_back(animalText);

    //Venus
    this->venusText = make_shared<Text>("0",vvenusText);
    this->venusText->setSizeText(textSize);
    this->venusText->setColor(sf::Color::White);
    this->listComponents.push_back(venusText);
    this->listText.push_back(venusText);

    //Space
    this->spaceText = make_shared<Text>("0",vspaceText);
    this->spaceText->setSizeText(textSize);
    this->spaceText->setColor(sf::Color::White);
    this->listComponents.push_back(spaceText);
    this->listText.push_back(spaceText);

    //Power
    this->powerText = make_shared<Text>("0",vpowerText);
    this->powerText->setSizeText(textSize);
    this->powerText->setColor(sf::Color::White);
    this->listComponents.push_back(powerText);
    this->listText.push_back(powerText);

    //Plant
    this->plantText = make_shared<Text>("0",vplantText);
    this->plantText->setSizeText(textSize);
    this->plantText->setColor(sf::Color::White);
    this->listComponents.push_back(plantText);
    this->listText.push_back(plantText);

    //Event
    this->eventText = make_shared<Text>("0",veventText);
    this->eventText->setSizeText(textSize);
    this->eventText->setColor(sf::Color::White);
    this->listComponents.push_back(eventText);
    this->listText.push_back(eventText);

    //Earth
    this->earthText = make_shared<Text>("0",vearthText);
    this->earthText->setSizeText(textSize);
    this->earthText->setColor(sf::Color::White);
    this->listComponents.push_back(earthText);
    this->listText.push_back(earthText);

    //City
    this->cityText = make_shared<Text>("0",vcityText);
    this->cityText->setSizeText(textSize);
    this->cityText->setColor(sf::Color::White);
    this->listComponents.push_back(cityText);
    this->listText.push_back(cityText);
}

PopupBadge::~PopupBadge() = default;

void PopupBadge::update(const unordered_map<string,string>& data) {
    if(opened) return;
    opened = true;

    //Building
    this->buildingText->setText(data.at("badge " + to_string(state::BUILDING)));

    //Science
    this->scienceText->setText(data.at("badge " + to_string(state::SCIENCE)));

    //Microbe
    this->microbeText->setText(data.at("badge " + to_string(state::MICROBE)));

    //Jovian
    this->jovianText->setText(data.at("badge " + to_string(state::JOVIAN)));

    //Animal
    this->animalText->setText(data.at("badge " + to_string(state::ANIMAL)));

    //Venus
    this->venusText->setText(data.at("badge " + to_string(state::VENUS)));

    //Space
    this->spaceText->setText(data.at("badge " + to_string(state::SPACE)));

    //Power
    this->powerText->setText(data.at("badge " + to_string(state::B_ENERGY)));

    //Plant
    this->plantText->setText(data.at("badge " + to_string(state::B_PLANT)));

    //Event
    this->eventText->setText(data.at("badge " + to_string(state::EVENT)));

    //Earth
    this->earthText->setText(data.at("badge " + to_string(state::EARTH)));

    //City
    this->cityText->setText(data.at("badge " + to_string(state::B_CITY)));

}

void PopupBadge::draw(sf::RenderWindow& window){
    for(const auto &component : this->listComponents){
        window.draw(*component);
    }
}

std::vector<std::shared_ptr<Button>> PopupBadge::getListButtons() {
    return listButtons;
}
