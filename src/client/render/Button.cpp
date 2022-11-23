#include "Button.h"
#include <iostream>

using namespace render;
using namespace std;

Button::Button() {
    this->position.x=0;
    this->position.y=0;
}

Button::Button(std::string fileName, sf::Vector2f position) {
    string path="../src/resources/"+fileName;
    if (!this->texture.loadFromFile(path)){
        cout<<"Error: font file not found"<<endl;
    }
    this->texture.setSmooth(true);

    //Define sprite
    this->sprite.setTexture(this->texture);

    //Set position
    this->position = position;
    this->sprite.setPosition(this->position);

    //Setting clickable arrea
    this->clickableArea = ClickableArea();

    //Settinig size
    this->size = sf::Vector2f(this->texture.getSize());
}

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
    this->sprite.setPosition(this->position);

    //Setting size
    this->size = sf::Vector2f(this->texture.getSize());
}

Button::~Button() {

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const  {
    target.draw(this->sprite,states);
}

void Button::setSize(const sf::Vector2f &size) {
    sf::Vector2f ratioScale(size.x/this->size.x, size.y/this->size.y);
    this->size = size;
    this->sprite.setScale(ratioScale);

}

