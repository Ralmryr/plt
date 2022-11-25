#include "PopupCard.h"

using namespace std;

render::PopupCard::PopupCard() {
    sf::Vector2f vbackground;
    sf::Vector2f vcloseButton;
    this->background = make_shared<Image>("background.png", vbackground);
    this->closeButton = make_shared<Button>("closeButton.png", vcloseButton);
    this->listComponents.push_back(this->background);
    this->listComponents.push_back(this->closeButton);

}

render::PopupCard::~PopupCard() {

}

void render::PopupCard::update(const std::unordered_map<std::string, std::string>& data) {
    if(data.size() > listComponents.size()) return;
    for(const auto& card : data) {
        string filename = "blabla/" + card.second;
        listComponents.push_back(make_shared<Button>(filename, sf::Vector2f(30, 30)));
    }
}

void render::PopupCard::draw(sf::RenderWindow& window) {
    for(const auto& component : listComponents) {
        window.draw(*component);
    }
}
