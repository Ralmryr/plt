#include "../constants.hpp"
#include "Text.h"
#include <iostream>

using namespace render;
using namespace std;

Text :: Text()= default;

Text::Text(std::string text, sf::Vector2f position){
    //Setting text
    this->text=std::move(text);
    this->textToDraw.setString(this->text);

    //Loading font
    if(!this->font.loadFromFile(RESS_PATH + "Prototype.ttf")){
    cout<<"Error: font file not found"<<endl;
    }

    //Setting text size
    this->sizeText=FONT_SIZE_DEFAULT;
    this->textToDraw.setFont(this->font);
    this->textToDraw.setString(this->text);
    this->textToDraw.setCharacterSize(this->sizeText);

    //Setting text position
    this->position = position;
    this->textToDraw.setPosition(this->position);

}

Text::~Text() = default;

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textToDraw,states);
}

void Text::setText(const string& text){
    this->text = text;
    this->textToDraw.setString(this->text);
}

void Text::setSizeText(int sizeText) {
    this->sizeText = sizeText;
    this->textToDraw.setCharacterSize(sizeText);
}

void Text::setColor(const sf::Color& color) {
    this->textToDraw.setFillColor(color);
}

const std::string &Text::getText() const {
    return this->text;
}




