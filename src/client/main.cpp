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
    image.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    Text text = Text("Terraforming !!", sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
    text.setSizeText(50);
    Button button = Button("badge_wild.png", sf::Vector2f(WINDOW_WIDTH/2 + 50, WINDOW_HEIGHT/2 + 50));
    button.setSize(sf::Vector2f(50,50));
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
        window.draw(image);
        window.draw(text);
        window.draw(button);
        window.display();
    }

    return 0;
}
