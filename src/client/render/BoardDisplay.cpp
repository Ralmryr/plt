#include <iostream>
#include <stdio.h>
#include "BoardDisplay.h"

using namespace render;
using namespace std;

BoardDisplay::BoardDisplay(){
    //Initializing images
    this->boardImage = Image("boardImage.png", sf::Vector2f(15,15));

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
    this->listComponents.push_back(make_shared<Image>(boardImage));
};

BoardDisplay::~BoardDisplay(){}

void BoardDisplay::update(unordered_map<string, string> data){
    for(auto const& dataEl : data){
        string type = dataEl.second.substr(0, dataEl.second.find(","));
        string player = dataEl.second.substr(1, dataEl.second.find(","));
        string x = dataEl.first.substr(0, dataEl.first.find(","));
        string y = dataEl.first.substr(1, dataEl.first.find(","));
        switch(stoi(type)){
            case 1://Forrest
                this->listComponents.push_back(make_shared(Image("forrest.png"), sf::Vector2f(x,y)));
                break;
            case 2://Ocean
                this->listComponents.push_back(make_shared(Image("ocean.png"), sf::Vector2f(x,y)));
                break;
            case 3://City
                this->listComponents.push_back(make_shared(Image("city.png"), sf::Vector2f(x,y)));
                break;
            case 4://Mine
                this->listComponents.push_back(make_shared(Image("mine.png"), sf::Vector2f(x,y)));
                break;
            case 5://Forbidden
                this->listComponents.push_back(make_shared(Image("forbidden.png"), sf::Vector2f(x,y)));
                break;
            case 6://Mohol
                this->listComponents.push_back(make_shared(Image("mohol.png"), sf::Vector2f(x,y)));
                break;
            case 7://Nuke
                this->listComponents.push_back(make_shared(Image("nuke.png"), sf::Vector2f(x,y)));
                break;
            case 8://Preserved
                this->listComponents.push_back(make_shared(Image("preserved.png"), sf::Vector2f(x,y)));
                break;
            case 9://Zoo
                this->listComponents.push_back(make_shared(Image("zoo.png"), sf::Vector2f(x,y)));
                break;
            case 10://Commercial
                this->listComponents.push_back(make_shared(Image("commercial.png"), sf::Vector2f(x,y)));
                break;
            case 11://Capital
                this->listComponents.push_back(make_shared(Image("capital.png"), sf::Vector2f(x,y)));
                break;
            case 12://Industry
                this->listComponents.push_back(make_shared(Image("industry.png"), sf::Vector2f(x,y)));
                break;

        }
    }

}

void BoardDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
