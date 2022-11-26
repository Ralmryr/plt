#include <iostream>
#include <utility>
#include "../constants.hpp"
#include "Image.h"

using namespace render;
using namespace std;

Image::Image(){
    this->position.x = 0;
    this->position.y = 0;
}


Image::~Image(){

}


Image::Image(string fileName, sf::Vector2f position) {
    //Setting position
    this->position = position;

    //Setting texture to the sprite
    auto texturePtr = texturePool.getTexturePtr(std::move(fileName));
    this->sprite.setTexture(*texturePtr);
    this->sprite.setPosition(this->position);

    //Setting size
    this->size = texturePtr->getSize();
}


Image::Image(std::string fileName, sf::Vector2f position, sf::Vector2u size) {
    //Setting position
    this->position = position;

    auto texturePtr = texturePool.getTexturePtr(std::move(fileName));
    this->sprite.setTexture(*texturePtr);
    this->sprite.setPosition(this->position);

    //Setting size
    auto spriteSize = texturePtr->getSize();
    sf::Vector2f ratioScale(float(size.x)/spriteSize.x, float(size.y)/spriteSize.y);
    this->size = size;
    this->sprite.setScale(ratioScale);
}


void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->sprite,states);
}


void Image::setSize(const sf::Vector2u &size) {
    sf::Vector2f ratioScale(float(size.x)/this->size.x, float(size.y)/this->size.y);
    this->size = size;
    this->sprite.setScale(ratioScale);
}


void Image::setScale(float scale) {
    this->sprite.setScale(scale, scale);
    this->size.x = unsigned(size.x * scale);
    this->size.y = unsigned(size.y * scale);
}


void Image::setRect(const sf::IntRect& rect) {
    this->sprite.setTextureRect(rect);
}


const sf::Vector2u &Image::getSize() const {
    return this->size;
}

void Image::setPosition(const sf::Vector2f &position) {
    this->position = position;
    this->sprite.setPosition(position);
}

const sf::Vector2f &Image::getPosition() const {
    return this->position;
}

