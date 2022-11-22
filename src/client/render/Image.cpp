#include <iostream>
#include "../constants.hpp"
#include "Image.h"

using namespace render;
using namespace std;

Image::Image(){
    this->position.x = 0;
    this->position.y = 0;
}

Image::Image(string fileName, sf::Vector2f position){
    //Setting position
    this->position = position;

    //Loading image file
    if(!this->texture.loadFromFile( RESS_PATH + fileName)){
        cout << "Erreur : la texture n'a pas été générée.." << endl;
    }
    this->texture.setSmooth(true);

    //Setting texture to the sprite
    this->sprite.setTexture(this->texture);
}

Image::~Image() {}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->sprite, states);
}

void Image::setTexture(const sf::Texture &texture) {
    this->texture = texture;
}

void Image::setSize(const sf::Vector2f& size){
    this->size = size;
}


