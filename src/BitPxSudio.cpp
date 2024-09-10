

#include <iostream>
#include<SFML/Graphics.hpp>
#include "../Button.h"


int main()
{

    Button button;

    sf::RenderWindow window(sf::VideoMode(600, 600), "sdc", sf::Style::Titlebar | sf::Style::Close);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(button);
        window.display();
    }


	return 0;
}
