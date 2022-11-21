#include <iostream>
#include "BoardDisplay.h"

using namespace render;
using namespace std;

BoardDisplay::BoardDisplay(){
    //Initializing images
    this->boardImage = Image("boardImage.png", sf::Vector2f(15,15));
    this->listTilesImage.push_back(Image("forest.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("ocean.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("city.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("mine.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("forbidden.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("mohol.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("nuke.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("preserved.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("zoo.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("commercial.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("capital.png",sf::Vector2f(15,15)));
    this->listTilesImage.push_back(Image("industry.png",sf::Vector2f(15,15)));

    //Adding the components to the list
    this->listComponents.push_back(make_unique<Image>(boardImage));
};

BoardDisplay::~BoardDisplay(){}

void BoardDisplay::update(unordered_map<string, string> data){
    for(auto const dataEl : data){
        listTilesImage
    }

}

void BoardDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
