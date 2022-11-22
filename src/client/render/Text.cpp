#include "Text.h"
#include <iostream>

using namespace render;
using namespace std;

Text :: Text()= default;

Text::Text(std::string text, sf::Vector2f position){
    //Setting text
    this->text=std::move(text);

    //Loading font
    if(!this->font.loadFromFile("../src/resources/arial.ttf")){
    cout<<"Error: font file not found"<<endl;
    }

    //Setting text size
    this->sizeText=24;

    this->position = position;
}

Text::~Text() = default;

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //Setting text parameters
    sf::Text textToDraw;
    textToDraw.setFont(this->font);
    textToDraw.setString(this->text);
    textToDraw.setCharacterSize(this->sizeText);
    //Drawing text
    target.draw(textToDraw,states);
}

void Text::setText(const string& text){
    this->text = text;
}





