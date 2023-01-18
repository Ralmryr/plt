#ifndef PLT_CONSTANTS_HPP
#define PLT_CONSTANTS_HPP

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

//--------SYSTEM CONSTANTS-----------
const string RESS_PATH = "../src/resources/";
const string CARDS_PATH = RESS_PATH + "cards/";
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

//---------AI CONSTANTS-------------
const int FOREST_ADJACENCY_VALUE_C = 10;
const int OCEAN_ADJACENCY_VALUE = 2;
const int CITY_ADJACENCY_VALUE_F = 10;
const int CARD_BONUS_PLACEMENT = 4;
const int IRON_BONUS_PLACEMENT = 2;
const int TITANIUM_BONUS_PLACEMENT = 3;
const int PLANT_BONUS_PLACEMENT = 1;

#endif //PLT_CONSTANTS_HPP
