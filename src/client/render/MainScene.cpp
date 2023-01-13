#include <iostream>
#include "MainScene.h"

using namespace std;

render::MainScene::MainScene(): playerScoreDisplay() , globalParametersDisplay(), boardDisplay(),menu(),stdProjectDisplay(){

}

render::MainScene::~MainScene() {

}

void render::MainScene::update(const unordered_map<string, string> &data) {

/*    for(const auto& element : data) {
        cout << "{ First : " << element.first << ", Second : " << element.second << " }" << endl;
    }
    */

    // Gather every entry that is only composed of idPlayer and gets their NT
    unordered_map<string, string> playScoreData;
    int idPlayer;
    string strIdPlayer;
    for(idPlayer=0;idPlayer<5;idPlayer++){
        strIdPlayer= to_string(idPlayer);
        if(data.find(strIdPlayer)!=data.end()){
            // The player exist
            playScoreData[strIdPlayer]=data.at(strIdPlayer);
        }
    }
    playerScoreDisplay.update(playScoreData);

    // Gather every entry related to global parameters
    unordered_map<string, string> globalParamData;
    globalParamData["Oxygen"]=data.at("Oxygen");
    globalParamData["Temperature"]=data.at("Temperature");
    globalParamData["NumberOceans"]=data.at("NumberOceans");
    globalParametersDisplay.update(globalParamData);

    // Gather every entry related to the tiles placed on board
    unordered_map<string, string> boardData;
    int x,y;
    string coords;
    for(x=-4;x<5;x++){
        for(y=-4;y<5;y++){
            coords= to_string(x) + ", " + to_string(y);
            if(data.find(coords)!=data.end()){
                // there is a tile with this coordinates
                boardData[coords]=data.at(coords);
            }
        }
    }
    boardDisplay.update(boardData);

    // Gather every entry "resource i" where i is the id of the resource in the enum
    unordered_map<string, string> resourceData;
    string resource;
    for(int i = state::R_FIRST+1; i != state::R_LAST; i++) {
        resource= "resource " + to_string(i);
        resourceData[resource]=data.at(resource);
    }
    resourceData["PV"]=data.at("PV");
    menu.update(resourceData);
}

void render::MainScene::draw(sf::RenderWindow &window) {
    boardDisplay.draw(window);
    playerScoreDisplay.draw(window);
    globalParametersDisplay.draw(window);
    menu.draw(window);
    stdProjectDisplay.draw(window);
}
