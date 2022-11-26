#include "Button.h"
#include <iostream>
#include <utility>

using namespace render;
using namespace std;

Button::Button() {
    this->position.x=0;
    this->position.y=0;
    this->hovered = false;
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

    //Setting size
    if(texturePtr != nullptr)
        this->size = this->sprite.getTexture()->getSize();

    this->clickableArea = sf::FloatRect(position.x, position.y, size.x, size.y);

    this->hovered = false;
}

Button::Button(string fileName, sf::Vector2f position, sf::FloatRect clickableArea) : Button(std::move(fileName), position){
    this->clickableArea = clickableArea;
    this->hovered = false;
}

Button::~Button() {

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const  {
    target.draw(this->sprite,states);
}

void Button::setSize(const sf::Vector2u &size) {
    sf::Vector2f ratioScale(float(size.x)/this->size.x, float(size.y)/this->size.y);
    this->size = size;
    this->sprite.scale(ratioScale);
}

void Button::setScale(float scale) {
    this->sprite.setScale(scale, scale);
    this->size.x = unsigned(size.x * scale);
    this->size.y = unsigned(size.y * scale);
}

const sf::FloatRect &Button::getClickableArea() const {
    return this->clickableArea;
}

void Button::updateClickableArea() {
    this->clickableArea.left = position.x;
    this->clickableArea.top = position.y;
    this->clickableArea.height = size.y;
    this->clickableArea.width = size.x;
}

const std::string &Button::getFunctionStr() const {
    return this->functionStr;
}

void Button::setFunctionStr(const string &functionStr) {
    this->functionStr = functionStr;
}

void Button::onMouseHover(bool hover) {
    // The mouse has juste entered the button
    if(hover && hover != hovered) {
        this->sprite.scale(1.25f, 1.25f);
        this->position.x -= this->size.x * 0.125f;
        this->position.y -= this->size.y * 0.125f;
        this->sprite.setPosition(this->position);
        hovered = hover;
    }
    // The mouse has juste left the button
    else if(!hover && hover != hovered) {
        this->sprite.scale(0.8f, 0.8f);
        this->position.x += this->size.x * 0.125f;
        this->position.y += this->size.y * 0.125f;
        this->sprite.setPosition(this->position);
        hovered = hover;
    }
}

