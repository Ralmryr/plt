#include <iostream>
#include "BoardDisplay.h"

using namespace render;
using namespace std;

BoardDisplay::BoardDisplay(){
    //Initializing images
    this->boardImage = make_shared<Image>(Image("boardImage.png", sf::Vector2f(15,15)));

    this->listTilesImage.push_back(make_shared<Image>(Image("forest.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("ocean.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("city.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("mine.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("forbidden.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("mohol.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("nuke.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("preserved.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("zoo.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("commercial.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("capital.png",sf::Vector2f(15,15))));
    this->listTilesImage.push_back(make_shared<Image>(Image("industry.png",sf::Vector2f(15,15))));

    //Adding the components to the list
    this->listComponents.push_back(boardImage);
};

BoardDisplay::~BoardDisplay(){}

void BoardDisplay::update(unordered_map<string, string> data){

}

void BoardDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
