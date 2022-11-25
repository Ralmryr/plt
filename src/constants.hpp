#ifndef PLT_CONSTANTS_HPP
#define PLT_CONSTANTS_HPP

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

//--------SYSTEM CONSTANTS-----------
const string RESS_PATH = "../src/resources/";
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const sf::Vector2u WINDOW_SIZE(WINDOW_WIDTH,WINDOW_HEIGHT);

//--------ENGINE CONSTANTS-----------
const int MAX_PLAYER = 5;
const int FONT_SIZE_DEFAULT = 24;
const int MIN_TEMPERATURE = -30;
const int MAX_TEMPERATURE = 8;
const int STARTING_TEMPERATURE = MIN_TEMPERATURE;
const int MIN_OXYGEN = 0;
const int MAX_OXYGEN = 14;
const int STARTING_OXYGEN = MIN_OXYGEN;
const int MAX_OCEAN = 9;
const int STARTING_OCEAN = 0;

//---------SF CONSTANTS--------------
const sf::Color COLOR_BLACK(0, 0, 0);
const sf::Color COLOR_WHITE(0, 0, 0);

#endif //PLT_CONSTANTS_HPP
