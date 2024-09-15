#include "../Window.h"
#include "../Button.h"
#include "../Container.h"
#include "../Zoom.h"

#define WINDOW_COLOR sf::Color(240, 237, 237)


void Window::setWindow() {
	Button button;
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	Board board;
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), TITLE, sf::Style::Titlebar | sf::Style::Close);
	Zoom zoom;
	zoom.view = window.getDefaultView();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			zoom.zoomEvent(event, window);
		}
		window.setView(zoom.view);
		window.clear(WINDOW_COLOR);
		window.draw(board);
		board.drawEvent(window);
		window.draw(button);
		window.display();
	}
}