#include "StdProjectDisplay.h"
#include <iostream>

using namespace render;
using namespace std;

StdProjectDisplay::StdProjectDisplay() {
    //frameImage
    unique_ptr <UiComponent> ptrFrameImage=&frameImage;
    //discardButton

    //prodEnergyButton

    //temperatureButton

    //oceanButton

    //forestButton

    //cityButton

    //listComponents
    listComponents.push_back(ptrFrameImage);

}

StdProjectDisplay::~StdProjectDisplay() {}

void StdProjectDisplay::draw(sf::RenderWindow &window) {

}

void StdProjectDisplay::update() {
}
