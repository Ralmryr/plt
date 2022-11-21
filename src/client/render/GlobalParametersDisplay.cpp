#include "GlobalParametersDisplay.h"

using namespace render;
using namespace std;

GlobalParametersDisplay::GlobalParametersDisplay(){
    //Initializing images
    tempFrameImage = Image("tempFrameImage.png", sf::Vector2f(15,15));
    tempFillImage = Image("tempFillImage.png", sf::Vector2f(15,15));
    tempLogoImage = Image("tempLogoImage.png", sf::Vector2f(15,15));
    oxyFrameImage = Image("oxyFrameImage.png", sf::Vector2f(15,15));
    oxyFillImage = Image("oxyFillImage.png", sf::Vector2f(15,15));
    oxyLogoImage = Image("oxyLogoImage.png", sf::Vector2f(15,15));
    oceanLogoImage = Image("oceanLogoImage.png", sf::Vector2f(15,15));

    //Initializing texts
    tempMinText = Text("-30 °C", sf::Vector2f(15,15));
    tempMaxText = Text("8 °C", sf::Vector2f(15,15));
    tempCurrentText = Text("-30 °C", sf::Vector2f(15,15));
    oxyMinText = Text("0 %", sf::Vector2f(15,15));
    oxyMaxText = Text("14 %", sf::Vector2f(15,15));
    oxyCurrentText = Text("0 %", sf::Vector2f(15,15));
    oceanCurrentText = Text("0/9", sf::Vector2f(15,15));


    //Adding the components to the list
    this->listComponents.push_back(make_unique<Image>(tempFrameImage));
    this->listComponents.push_back(make_unique<Image>(tempFillImage));
    this->listComponents.push_back(make_unique<Image>(tempLogoImage));
    this->listComponents.push_back(make_unique<Text>(tempMinText));
    this->listComponents.push_back(make_unique<Text>(tempMaxText));
    this->listComponents.push_back(make_unique<Text>(tempCurrentText));
    this->listComponents.push_back(make_unique<Image>(oxyFrameImage));
    this->listComponents.push_back(make_unique<Image>(oxyFillImage));
    this->listComponents.push_back(make_unique<Image>(oxyLogoImage));
    this->listComponents.push_back(make_unique<Text>((oxyMinText)));
    this->listComponents.push_back(make_unique<Text>(oxyMaxText));
    this->listComponents.push_back(make_unique<Text>(oxyCurrentText));
    this->listComponents.push_back(make_unique<Image>(oceanLogoImage));
    this->listComponents.push_back(make_unique<Text>(oceanCurrentText));
}

GlobalParametersDisplay::~GlobalParametersDisplay(){}

void GlobalParametersDisplay::update(unordered_map<string,string> data){
    //Getting current temperature oxygene and ocean datas
    int temp = stoi(data["Temperature"]);
    int oxy = stoi(data["Oxygene"]);

    //Setting new data texts
    tempCurrentText.setText(data["Temperature"] + " ° C");
    oxyCurrentText.setText(data["Oxygene"] + " %");
    oceanCurrentText.setText(data["Ocean"] + "/9");

    //Setting new sprite size for the fillers
    tempFillImage.setSize(sf::Vector2f(tempFillImage.getSize().x*temp, tempFillImage.getSize().y*temp));
    oxyFillImage.setSize(sf::Vector2f(oxyFillImage.getSize().x*oxy, oxyFillImage.getSize().y*oxy));

}

void GlobalParametersDisplay::draw(sf::RenderWindow& window){
    for(auto const &component : listComponents){
        window.draw(*component);
    }
}

void GlobalParametersDisplay::setListComponents(const std::vector<std::unique_ptr<sf::Drawable>>& listComponents){}