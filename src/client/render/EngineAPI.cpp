#include "EngineAPI.h"

#include <utility>
#include <iostream>

using namespace render;
using namespace std;


EngineAPI::EngineAPI() {

}

EngineAPI::~EngineAPI() {

}

void EngineAPI::loadButtons(std::vector<std::shared_ptr<Button>> lButtons) {
    listButtons = std::move(lButtons);
    listHitbox.clear();
    for(const auto& button : listButtons) {
        listHitbox.push_back(button->getClickableArea());
    }
}

void EngineAPI::onClick(sf::Vector2f coords, std::shared_ptr<SharedContext> sharedContext) {
    int i = 0;
    for(const auto& hitbox : listHitbox) {
        if(hitbox.contains(coords)) {
            currentCommand = listButtons[i]->getFunctionStr();
        }
        i++;
    }
    /*
    // Here are treated the commands that directly influence render
    if(currentCommand == "Open Cards Hand") {
        scene.addScene(CARDS_VIEW);
        currentCommand = "";
    }
    else if(currentCommand == "Close Cards Hand") {
        scene.removeScene();
        currentCommand = "";
    } */
}

// Returns the commands and clears it
std::string EngineAPI::provideCommandStr() {
    auto returnStr = currentCommand;
    currentCommand = "";
    return returnStr;
}

void EngineAPI::onMouseMoved(sf::Vector2f coords) {
    int i = 0;
    for(const auto& hitbox : listHitbox) {
        if(hitbox.contains(coords))
            listButtons[i]->onMouseHover(true);
        else
            listButtons[i]->onMouseHover(false);
        i++;
    }
}
