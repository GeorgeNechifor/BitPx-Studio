#include "../Window.h"
#include "../Button.h"


void Window::setWindow() {
	Button button;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE, sf::Style::Titlebar | sf::Style::Close);
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

}