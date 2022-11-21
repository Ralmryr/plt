#include "Button.h"
#include <iostream>

using namespace render;
using namespace std;

Button::Button(string fileName, ClickableArea clickableArea, sf::Vector2f position) {
    this->clickableArea=clickableArea;
    //Define texture
    string path="../src/resources/"+fileName;
    if (!this->texture.loadFromFile(path)){
        cout<<"Error: font file not found"<<endl;
    }
    this->texture.setSmooth(true);

    //Define sprite
    this->sprite.setTexture(this->texture);

    //Set position
    this->position = position;
}

Button::~Button() {

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const  {
    target.draw(this->sprite,states);
}

void Button::update() {
    //To code
}
