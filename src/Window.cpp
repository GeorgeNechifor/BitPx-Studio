#include "../Window.h"
#include "../Button.h"
#include "../Container.h"
#include "../Board.h"

void Window::setWindow() {
	Button button;
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	Board board;
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), TITLE, sf::Style::Titlebar | sf::Style::Close);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::White);
		window.draw(button);
		window.draw(board);
		window.display();
	}
}