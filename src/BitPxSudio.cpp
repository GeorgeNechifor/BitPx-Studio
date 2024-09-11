

#include <iostream>
#include<SFML/Graphics.hpp>
#include "../Button.h"
#include "../CustomText.h"

int main()
{

    Button button;
    Button btn2;
    btn2.setButtonPosition(sf::Vector2f(20.f, 100.f));
    CustomText text;
    text.setTextColor(sf::Color::Red);
    
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
        window.draw(btn2);
        window.draw(text);
        window.display();
    }


	return 0;
}
