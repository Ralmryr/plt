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
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "Terraforming Mars",
                            sf::Style::Fullscreen);
    //initializing scene
    Scene scene = Scene();

    sf::Clock clock;
    sf::Time elapsedTime;

    while (window.isOpen())
    {
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }

        }

        window.clear(sf::Color::Black);
        scene.draw(window);
        window.display();

        elapsedTime = clock.getElapsedTime();
        //cout << "Elapsed time : " << elapsedTime.asMilliseconds() << endl;
        clock.restart();
    }

    return 0;
}
