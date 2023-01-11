#include "BoardScene.h"

using namespace std;

render::BoardScene::BoardScene(): playerScoreDisplay() , globalParametersDisplay(), boardDisplay(),menu(),stdProjectDisplay(){

}

render::BoardScene::~BoardScene() {

}

void render::BoardScene::update(const unordered_map<string, string> &data) {

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

    unordered_map<string, string> globalParamData;
    globalParamData["Oxygen"]=data.at("Oxygen");
    globalParamData["Temperature"]=data.at("Temperature");
    globalParamData["NumberOceans"]=data.at("NumberOceans");
    globalParametersDisplay.update(globalParamData);

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

    unordered_map<string, string> menuData;
    string resource;
    for(int i = state::R_FIRST+1; i != state::R_LAST; i++) {
        resource= "resource " + to_string(i);
        menuData[resource]=data.at(resource);
    }
    menuData["PV"]=data.at("PV");
    menu.update(menuData);
}

void render::BoardScene::draw(sf::RenderWindow &window) {
    playerScoreDisplay.draw(window);
    globalParametersDisplay.draw(window);
    boardDisplay.draw(window);
    menu.draw(window);
    stdProjectDisplay.draw(window);
}
