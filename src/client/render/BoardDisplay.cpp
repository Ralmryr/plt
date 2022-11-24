#include <iostream>
#include "BoardDisplay.h"
#include "../../constants.hpp"

using namespace render;
using namespace std;

BoardDisplay::BoardDisplay(){
    //Initializing images
    this->boardImage = make_shared<Image>("backgroundNew.png", sf::Vector2f(0,0));

    //Adding the components to the list
    this->listComponents.push_back(boardImage);
};

BoardDisplay::~BoardDisplay()= default;

void BoardDisplay::update(const unordered_map<string, string> &data){
    // Early exit (clause guard) if there is no new tile
    if(data.size() == listTilesPlaced.size()) return;

    for(auto const& dataEl : data){
        // If the tile has already been placed we keep traversing the data
        if(listTilesPlaced.find(dataEl.first) != listTilesPlaced.end()) continue;

        // Else that means the tile has not been placed yet, so we unpack its data
        string type = dataEl.second.substr(0, dataEl.second.find(","));
        string player = dataEl.second.substr(dataEl.second.find(",")+1);

        // Coordinates of tile in board reference
        int posX = stoi(dataEl.first.substr(0, dataEl.first.find(",")));
        int posY = stoi(dataEl.first.substr(dataEl.first.find(",")+1));

        // Everything we will need to calculate the final position
        sf::Vector2f spriteSize = {60, 69};
        sf::Vector2f centerBoard = {960, 420};
        string filename;

        switch(stoi(type)){
            case 1: //Forest
                filename = "forest.png";
                break;
            case 2: //Ocean
                filename = "ocean.png";
                break;
            case 3: //City
                filename = "city.png";
                break;
            case 4: //Mine
                filename = "mine.png";
                break;
            case 5: //Forbidden
                filename = "forbidden.png";
                break;
            case 6: //Mohol
                filename = "mohol.png";
                break;
            case 7: //Nuke
                filename = "nuke.png";
                break;
            case 8: //Preserved
                filename = "preserved.png";
                break;
            case 9: //Zoo
                filename = "zoo.png";
                break;
            case 10: //Commercial
                filename = "commercial.png";
                break;
            case 11: //Capital
                filename = "capital.png";
                break;
            case 12: //Industry
                filename = "industry.png";
                break;
        }

        float x = centerBoard.x + (float(posY) - 1) * spriteSize.x/2;
        float y = centerBoard.y  - (2 * float(posX)+ 1) * spriteSize.y/2;

        auto newImage = make_unique<Image>(filename, sf::Vector2f(x, y));
        newImage->setSize(sf::Vector2u(60, 69));
        this->listComponents.push_back(std::move(newImage));
        listTilesPlaced.insert(dataEl.first);
    }
}

void BoardDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : this->listComponents){
        window.draw(*component);
    }
}
