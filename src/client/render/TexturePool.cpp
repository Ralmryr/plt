#include "TexturePool.h"
#include <iostream>
#include "../constants.hpp"

using namespace std;
using namespace render;

render::TexturePool::TexturePool() {

}

render::TexturePool::~TexturePool() {

}

shared_ptr<sf::Texture> TexturePool::getTexturePtr(string filename) {
    filename = RESS_PATH + filename;
    // If the texture has not been loaded yet
    if (textureLoaded.find(filename) == textureLoaded.end())
    {
        auto newTexture = make_shared<sf::Texture>();
        if (!newTexture->loadFromFile(filename))
        {
            cout << "Couldn't load from filename : " << filename << endl;
            return nullptr;
        }
        newTexture->setSmooth(true);
        textureLoaded.insert({ filename, newTexture });
    }
    return textureLoaded[filename];
}

shared_ptr<sf::Texture> TexturePool::getCardPtr(string filename) {
    filename = CARDS_PATH + filename;
    // If the texture has not been loaded yet
    if (textureLoaded.find(filename) == textureLoaded.end())
    {
        auto newTexture = make_shared<sf::Texture>();
        if (!newTexture->loadFromFile(filename))
        {
            cout << "Couldn't load from filename : " << filename << endl;
            return nullptr;
        }
        newTexture->setSmooth(true);
        textureLoaded.insert({ filename, newTexture });
    }
    return textureLoaded[filename];
}

