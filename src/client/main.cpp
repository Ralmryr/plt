#include <iostream>
#include "render.h"
#include "state.h"
#include "../constants.hpp"
#include <SFML/Graphics.hpp>

using namespace render;
using namespace state;
using namespace std;

int main(int argc,char* argv[])
{
    // Quick SFML test that launches a black window that can be closed
    //create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Terraforming Mars");

    //initializing scene

    //create textures

    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("../src/client/img/background.png",sf::IntRect(0,0,1200,728))){
        printf("Erreur: la texture n'a pas été générée");
    }
    textureBackground.setSmooth(true);

    //create sprites
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);

    sf::RectangleShape RessourceCadre(sf::Vector2f(1850,310));
    RessourceCadre.setFillColor(sf::Color(250,250,250));
    RessourceCadre.setPosition((sf::Vector2f(0,770)));

    sf::RectangleShape RessourceLocation(sf::Vector2f(1835,235));
    RessourceLocation.setFillColor(sf::Color(0,0,0));
    RessourceLocation.setPosition((sf::Vector2f(5,775)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        //Define what is inside the window

        window.draw(spriteBackground);

        window.draw(RessourceCadre);
        window.draw(RessourceLocation);
        //

        window.display();
    }

    return 0;
}
