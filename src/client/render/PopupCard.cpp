#include "PopupCard.h"

using namespace std;

render::PopupCard::PopupCard() {

}

render::PopupCard::~PopupCard() {

}

void render::PopupCard::update(std::unordered_map<std::string, std::string> data) {
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
