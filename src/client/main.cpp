#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc,char* argv[])
{
    // Quick SFML test that launches a black window that can be closed
    //create window
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Terraforming Mars");
    //sf::RenderWindow window(sf::VideoMode(1920,1080), "Terraforming Mars",sf::Style::Fullscreen);

    //define font text
    /*sf::Font font;
    if (!font.loadFromFile("arial.ttf")){
        printf("Erreur: la police d'écriture n'a pas été trouvée");
    }*/

    //define text
    sf::Text textRessource;
    textRessource.setString("Ressource");
    textRessource.setCharacterSize(24);
    textRessource.setFillColor(sf::Color::White);
    //create textures
    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("Mars.jpeg",sf::IntRect(0,0,1200,728))){
        printf("Erreur: la texture n'a pas été générée");
    }
    textureBackground.setSmooth(true);

    //create sprites
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);

    sf::RectangleShape RessourceLocation(sf::Vector2f(250,728));
    RessourceLocation.setFillColor(sf::Color(100,100,100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        //Define what is inside the window
        window.draw(spriteBackground);
        window.draw(RessourceLocation);
        window.draw(textRessource);
        //

        window.display();
    }

    return 0;
}
