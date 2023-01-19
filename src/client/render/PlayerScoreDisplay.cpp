#include <iostream>
#include "PlayerScoreDisplay.h"

using namespace render;
using namespace std;

sf::Vector2f varrow = {300,50};

PlayerScoreDisplay::PlayerScoreDisplay(){
    //Setting positions for components
    sf::Vector2f vframe = {0, 0};
    sf::Vector2f vtitle = {20, 10};

    //Initializing images
    this->frameImage = make_shared<Image>("scorePlayerFrameImage.png", vframe);
    this->arrowImage = make_shared<Image>("turnArrow.png", varrow);
    this->arrowImage->setScale(0.1f);

    //Initializing texts
    this->titleText = make_shared<Text>("Niveau de terraformation", vtitle);

    // Add them to the component list
    this->listComponents.push_back(this->frameImage);
    this->listComponents.push_back(this->arrowImage);
    this->listComponents.push_back(this->titleText);

    sf::Color arrayColors[5] = {sf::Color::Blue,
                                sf::Color::Green,
                                sf::Color(255, 0, 220),
                                sf::Color::Red,
                                sf::Color(200, 125, 0)};

    for(int i = 0; i < 5; i++) {
        // Defines the position of each element
        sf::Vector2f posPlayerName = {15, float(50 + 70*i)};
        sf::Vector2f posPlayerScore = {250, float(50 + 70*i)};
        sf::Vector2f posPlayerCompany = {40, float(80 + 70*i)};
        // Creates each text and add them to its sorresponding list
        this->listPlayerText.push_back(make_shared<Text>("Joueur " + to_string(i+1), posPlayerName));
        listPlayerText[i]->setColor(arrayColors[i]);
        this->listScorePlayer.push_back(make_shared<Text>(to_string(i*100), posPlayerScore));
        this->listCompanyText.push_back(make_shared<Text>("Company : None", posPlayerCompany));
        this->listCompanyText.back()->setSizeText(20);
        // Adds each text to the list of components to draw
        this->listComponents.push_back(listPlayerText.back());
        this->listComponents.push_back(listScorePlayer.back());
        this->listComponents.push_back(listCompanyText.back());
        this->listComponents.push_back(make_shared<Image>("nt.png",
                                                          sf::Vector2f(190, float(50 + 70*i)),
                                                          sf::Vector2u(43, 31)));
    }
}

PlayerScoreDisplay::~PlayerScoreDisplay() {

}

void PlayerScoreDisplay::update(const std::unordered_map<std::string, std::string>& data){
    auto dataMap = data;
    int idCurrentPlayer = stoi(data.at("idPlayer"));
    dataMap.erase("idPlayer");


    // Updates the score for each player
    for (const auto &dataEl: dataMap) {
        int idPlayer = stoi(dataEl.first);
        listScorePlayer[idPlayer]->setText(dataEl.second);
    }

    arrowImage->setPosition({varrow.x, varrow.y+70*idCurrentPlayer});
}

void PlayerScoreDisplay::draw(sf::RenderWindow &window) {
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
