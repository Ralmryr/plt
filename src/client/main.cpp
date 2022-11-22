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
    Image image = Image("background.png", sf::Vector2f(0,0));
    BoardDisplay bd = BoardDisplay();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        bd.draw(window);
        window.display();
    }

    return 0;
}
