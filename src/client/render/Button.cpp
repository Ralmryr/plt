#include "Button.h"
#include <iostream>

using namespace render;
using namespace std;

Button::Button() {
    this->position.x=0;
    this->position.y=0;
}

Button::Button(std::string fileName, sf::Vector2f position) {

    //Setting texture to the sprite
    auto texturePtr = texturePool.getTexturePtr(std::move(fileName));
    if(texturePtr != nullptr)
        this->sprite.setTexture(*texturePtr);
    this->sprite.setPosition(this->position);

    //Set position
    this->position = position;
    this->sprite.setPosition(this->position);

    //Setting clickable arrea
    this->clickableArea = ClickableArea();

    //Settinig size
    this->size = this->texture.getSize();
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
    this->size = this->texture.getSize();
}

Button::~Button() {

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const  {
    target.draw(this->sprite,states);
}

void Button::setSize(const sf::Vector2u &size) {
    sf::Vector2f ratioScale(float(size.x)/this->size.x, float(size.y)/this->size.y);
    this->size = size;
    this->sprite.setScale(ratioScale);

}

void Button::setScale(float scale) {
    this->sprite.setScale(scale, scale);
}

