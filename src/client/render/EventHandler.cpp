#include "EventHandler.h"

#include <utility>
#include <iostream>

using namespace render;
using namespace std;


EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

void EventHandler::loadButtons(std::vector<std::shared_ptr<Button>> lButtons) {
    listButtons = std::move(lButtons);
    listHitbox.clear();
    for(const auto& button : listButtons) {
        listHitbox.push_back(button->getClickableArea());
    }
}

void EventHandler::onClick(sf::Vector2f coords) {
    int i = 0;
    for(const auto& hitbox : listHitbox) {
        if(hitbox.contains(coords)) {
            listButtons[i]->onClick(sharedContext);
        }
        i++;
    }
}

void EventHandler::onMouseMoved(sf::Vector2f coords) {
    int i = 0;
    for(const auto& hitbox : listHitbox) {
        if(hitbox.contains(coords))
            listButtons[i]->onMouseHover(true);
        else
            listButtons[i]->onMouseHover(false);
        i++;
    }
}

void EventHandler::hookSharedContext(std::shared_ptr<SharedContext> sharedContext) {
    this->sharedContext = std::move(sharedContext);
}

void EventHandler::handleEvent(sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed){
        onClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    }
    else if(event.type == sf::Event::MouseMoved) {
        onMouseMoved(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }

}
