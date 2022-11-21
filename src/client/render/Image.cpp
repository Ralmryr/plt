#include <iostream>
#include "Image.h"

using namespace render;
using namespace std;

Image::Image():UiComponent(){

}

Image::Image(string fileName, sf::Vector2f position):UiComponent(position){
    if(!this->texture.loadFromFile(fileName)){
        cout << "Erreur : la texture n'a pas été générée.." << endl;
    }
    this->texture.setSmooth(true);
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

void Image::update(){

}

