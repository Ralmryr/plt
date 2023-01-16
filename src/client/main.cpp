#include <iostream>
#include <fstream>
#include "render.h"
#include "state.h"
#include "../constants.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <engine.h>

using namespace render;
using namespace state;
using namespace engine;
using namespace std;


int main(int argc,char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "Terraforming Mars",
                            sf::Style::Fullscreen);

    window.setFramerateLimit(60);

    // Initialize state
    auto state = make_shared<State>();

    // Initialize EventManager
    auto eventManager = make_shared<EventManager>();
    eventManager->hookState(state);
    eventManager->initPermanentReactions();

    // Initialize connection between state and engine
    auto  eventSender = make_shared<EventSender>();
    eventSender->hookEventManager(eventManager);
    state->hookEventSender(eventSender);

    // Initialize sceneManager
    auto sceneManager = make_shared<SceneManager>();
    sceneManager->hookData(state->getUiDataProvider());
    sceneManager->addScene(render::BOARD_VIEW);

    // Initialize sharedContext
    auto sharedContext = make_shared<SharedContext>(sceneManager, eventManager);
    sceneManager->getEventHandler()->hookSharedContext(sharedContext);

    sf::Clock clock;
    sf::Time elapsedTime;

    // Assets to display FPS and mouse position
    auto fpsText = Text("0", sf::Vector2f(1700, 10));
    auto mouseText = Text("0, 0", sf::Vector2f(1700,50));
    int counterFps = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
            sceneManager->handleEvent(event);
        }
        sceneManager->update();
        sceneManager->draw(window);

        // Displays mouse position and FPS
        auto mousePosition = sf::Mouse::getPosition();
        mouseText.setText("Pos : " + to_string(mousePosition.x) + "," + to_string(mousePosition.y));
        window.draw(mouseText);
        elapsedTime = clock.getElapsedTime();
        if(counterFps++%10 == 0) // Will count fps every 10 frames
            fpsText.setText(to_string(1000/elapsedTime.asMilliseconds()));
        window.draw(fpsText);

        clock.restart();

        window.display();
    }

    cout << "End of program" << endl;
    return 0;
}