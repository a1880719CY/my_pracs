// Demonstrate sprite drawing in SFML
#include "SFML/Graphics.hpp"
#include "Character.h"

int main(){
    int windowWidth = 600;
    int windowLength = 600;
    sf::RenderWindow renderWindow(sf::VideoMode(windowLength, windowWidth), "Testing Character movement");

    sf::Event event;

    Character character1("texture\\theguddoge.png", 0.25f, 0.25f, windowLength, windowWidth);

    //sf::Texture TextureIcon;
    //TextureIcon.loadFromFile("texture\\theguddoge.png");
    //sf::Sprite tempSprite(TextureIcon);
    //tempSprite.setScale(0.25f, 0.25f);
    //tempSprite.setPosition( windowWidth/2, windowLength/2);

    //Character character1(tempSprite, windowWidth/2, windowLength/2);

    sf::Texture texture2;
    texture2.loadFromFile("texture\\walterdog.png");

    sf::Sprite sprite2(texture2);
    sprite2.setScale(0.4f, 0.4f);


    renderWindow.clear(sf::Color::Black);
    renderWindow.draw(sprite2);
    renderWindow.draw(character1.getIcon());
    renderWindow.display();

    while (renderWindow.isOpen()){

        while (renderWindow.pollEvent(event)){

            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                renderWindow.close();
                break;
            
            case sf::Event::EventType::KeyPressed:

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    // W is pressed: move our character upward
                    character1.move( 0, -100, windowWidth, windowLength);

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    // S is pressed: move our character upward
                    character1.move( 0, 100, windowWidth, windowLength);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    // A is pressed: move our character upward
                    character1.move( -100, 0, windowWidth, windowLength);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    // A is pressed: move our character upward
                    character1.move( 100, 0, windowWidth, windowLength);
                } 
                renderWindow.clear(sf::Color::Black);
                renderWindow.draw(sprite2);
                renderWindow.draw(character1.getIcon());
                renderWindow.display();
                break;

            }

        }

    }
}