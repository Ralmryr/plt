#include <iostream>
#include <fstream>
#include "render.h"
#include "state.h"
#include "../constants.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <../../extern/jsoncpp-1.8.0/json/json.h>

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

    // Initialize scene
    Scene scene = Scene();
    // Initialize state
    auto state = make_shared<State>();
    // Creates a bridge between the ui and the state
    scene.hookData(state->getUiDataProvider());

    scene.setScene(render::BOARD_VIEW);

    auto eventManager = EventManager();
    eventManager.hookState(state);


    auto eventDetails1 = StateEventDetails(engine::CARD_PLAYED);
    eventDetails1.setTilePosition({0, 0}).setIdPlayer(0);
    auto eventDetails2 = StateEventDetails(engine::TILE_PLACED);
    eventDetails2.setTilePosition({1, 2}).setIdPlayer(0);
    eventManager.notify(eventDetails1);
    eventManager.notify(eventDetails2);


    sf::Clock clock;
    sf::Time elapsedTime;

    // Assets to display FPS and mouse position
    auto fpsText = Text("0", sf::Vector2f(1700, 10));
    auto mouseText = Text("0, 0", sf::Vector2f(1700,50));
    int counterFps = 0;

    //Testing JSON
    ifstream ifs(RESS_PATH + "cards_description.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);


    for(int i = 0; i < obj.size(); i++) {
        cout << "Id: " << obj[i]["id"].asString() << " ";
        cout << "Cost: " << obj[i]["cost"].asString() << " ";
        cout << "Badges: ";
        for(int j = 0; j < obj[i]["badges"].size(); j++)
        {
            cout << obj[i]["badges"][j].asString() << ", ";
        }
        cout << "Effects: ";
        for(int j = 0; j < obj[i]["badges"].size(); j++)
        {
            cout << obj[i]["effects"][j].asString() << ", ";
        }
        cout << "Condition: " << obj[i]["condition"].asString() << endl;
    }

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
            scene.handleEvent(event);
        }
        scene.update();
        scene.draw(window);

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
    return 0; 
}