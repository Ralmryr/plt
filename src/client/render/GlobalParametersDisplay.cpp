#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

GlobalParametersDisplay::GlobalParametersDisplay(){
    //Initializing images
    tempFrameImage = make_shared<Image>(Image("tempFrameImage.png", sf::Vector2f(15,15)));
    tempFillImage = make_shared<Image>(Image("tempFillImage.png", sf::Vector2f(15,15)));
    tempLogoImage = make_shared<Image>(Image("tempLogoImage.png", sf::Vector2f(15,15)));
    oxyFrameImage = make_shared<Image>(Image("oxyFrameImage.png", sf::Vector2f(15,15)));
    oxyFillImage = make_shared<Image>(Image("oxyFillImage.png", sf::Vector2f(15,15)));
    oxyLogoImage = make_shared<Image>(Image("oxyLogoImage.png", sf::Vector2f(15,15)));
    oceanLogoImage = make_shared<Image>(Image("oceanLogoImage.png", sf::Vector2f(15,15)));

    //Initializing texts
    tempMinText = make_shared<Text>(Text("-30 °C", sf::Vector2f(15,15)));
    tempMaxText = make_shared<Text>(Text("8 °C", sf::Vector2f(15,15)));
    tempCurrentText = make_shared<Text>(Text("-30 °C", sf::Vector2f(15,15)));
    oxyMinText = make_shared<Text>(Text("0 %", sf::Vector2f(15,15)));
    oxyMaxText = make_shared<Text>(Text("14 %", sf::Vector2f(15,15)));
    oxyCurrentText = make_shared<Text>(Text("0 %", sf::Vector2f(15,15)));
    oceanCurrentText = make_shared<Text>(Text("0/9", sf::Vector2f(15,15)));


    //Adding the components to the list
    this->listComponents.push_back(tempFrameImage);
    this->listComponents.push_back(tempFillImage);
    this->listComponents.push_back(tempLogoImage);
    this->listComponents.push_back(tempMinText);
    this->listComponents.push_back(tempMaxText);
    this->listComponents.push_back(tempCurrentText);
    this->listComponents.push_back(oxyFrameImage);
    this->listComponents.push_back(oxyFillImage);
    this->listComponents.push_back(oxyLogoImage);
    this->listComponents.push_back(oxyMinText);
    this->listComponents.push_back(oxyMaxText);
    this->listComponents.push_back(oxyCurrentText);
    this->listComponents.push_back(oceanLogoImage);
    this->listComponents.push_back(oceanCurrentText);
}

GlobalParametersDisplay::~GlobalParametersDisplay(){}

void GlobalParametersDisplay::update(unordered_map<string,string> data){
    //Getting current temperature oxygene and ocean datas
    int temp = stoi(data["Temperature"]);
    int oxy = stoi(data["Oxygene"]);

    //Setting new data texts
    tempCurrentText->setText(data["Temperature"] + " ° C");
    oxyCurrentText->setText(data["Oxygene"] + " %");
    oceanCurrentText->setText(data["Ocean"] + "/9");

    //Setting new sprite size for the fillers
    tempFillImage->setSize(sf::Vector2f(tempFillImage->getSize().x*temp, tempFillImage->getSize().y*temp));
    oxyFillImage->setSize(sf::Vector2f(oxyFillImage->getSize().x*oxy, oxyFillImage->getSize().y*oxy));

}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}