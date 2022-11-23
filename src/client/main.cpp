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
    window.setFramerateLimit(60);
    //initializing scene
    Scene scene = Scene();

    sf::Clock clock;
    sf::Time elapsedTime;

    // Assets to display FPS and mouse position
    auto fpsText = Text("0", sf::Vector2f(1700, 10));
    auto mouseText = Text("0, 0", sf::Vector2f(1700,50));
    int counterFps = 0;

    while (window.isOpen())
    {
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

        // Displays mouse position and FPS
        auto mousePosition = sf::Mouse::getPosition();
        mouseText.setText("Pos : " + to_string(mousePosition.x) + "," + to_string(mousePosition.y));
        window.draw(mouseText);
        elapsedTime = clock.getElapsedTime();
        if(counterFps++%10 == 0) // Will count fps every 30 frames
            fpsText.setText(to_string(1000/elapsedTime.asMilliseconds()));
        window.draw(fpsText);

        clock.restart();
        window.display();
    }

    return 0;
}
