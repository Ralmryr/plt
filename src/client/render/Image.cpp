#include <iostream>
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

    //Loading image file
    if (!this->texture.loadFromFile(RESS_PATH + fileName)) {
        cout << "Erreur : la texture n'a pas été générée.." << endl;
    }
    this->texture.setSmooth(true);

    //Setting texture to the sprite
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position);

    //Setting size
    this->size = sf::Vector2f(this->texture.getSize());
}

void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->sprite,states);
}

/*void Image::setTexture(const sf::Texture &texture) {
    this->texture = texture;
}

void Image::setSize(const sf::Vector2f &size) {
    sf::Vector2f ratioScale(size.x/this->size.x, size.y/this->size.y);
    this->size = size;
    this->sprite.setScale(ratioScale);

}

