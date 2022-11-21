#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc,char* argv[])
{
    // Quick SFML test that launches a black window that can be closed
    sf::RenderWindow window(sf::VideoMode(800, 600), "Our window");

    sf::Texture textureIcon;
    if(!textureIcon.loadFromFile("../src/client/Resources/badge_venus.png")){
        cout << "Could not open file :'(" << endl;
    }
    textureIcon.setSmooth(true);

    sf::Sprite spriteIcon;
    spriteIcon.setTexture(textureIcon);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(spriteIcon);

        window.display();
    }

    return 0;
}
