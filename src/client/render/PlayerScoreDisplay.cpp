#include <iostream>
#include "PlayerScoreDisplay.h"

using namespace render;
using namespace std;

PlayerScoreDisplay::PlayerScoreDisplay(){
    //Setting positions for components
    sf::Vector2f vframe = {0, 0};
    sf::Vector2f vtitle;

    //Initializing images
    this->frameImage = make_shared<Image>("scorePlayerFrameImage.png", vframe);


    //Initializing texts
    this->titleText = make_shared<Text>("Niveau de terraformation", vtitle);
    this->listPlayerText.push_back(make_shared<Text>("Joueur 1", sf::Vector2f(15,15)));
    this->listScorePlayer.push_back(make_shared<Text>("0", sf::Vector2f(15,15)));
    this->listCompanyText.push_back(make_shared<Text>("Company : None", sf::Vector2f(15,15)));

    //Adding the components to the list
    this->listComponents.push_back(this->frameImage);
    this->listComponents.push_back(this->titleText);
    for(auto const &pText : this->listPlayerText){
        this->listComponents.push_back(pText);
    }
    for(auto const &sText : this->listScorePlayer){
        this->listComponents.push_back(sText);
    }
    for(auto const &cText : this->listCompanyText){
        this->listComponents.push_back(cText);
    }
}

PlayerScoreDisplay::~PlayerScoreDisplay() {

}

void PlayerScoreDisplay::update(std::unordered_map<std::string, std::string> data){

}

void PlayerScoreDisplay::draw(sf::RenderWindow &window) {
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
