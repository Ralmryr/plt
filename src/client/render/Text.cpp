#include "Text.h"
#include <iostream>

using namespace render;
using namespace std;

Text::Text(std::string text) {
    this->text=text;
    if(!this->font.loadFromFile("../src/resources/arial.ttf")){
        cout<<"Error: font file not found"<<endl;
    }
    this->size=24;
}

Text::~Text() {}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Text textToDraw;
    textToDraw.setFont(this->font);
    textToDraw.setString(this->text);
    textToDraw.setCharacterSize(this->size);
    target.draw(textToDraw,states);
}

void Text::update() {
    //To code
}

