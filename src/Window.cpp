#include "../Window.h"
#include "../Button.h"
#include "../Container.h"
#include "../Zoom.h"
#include "../Color.h"
#include"../Tools.h"

#define WINDOW_COLOR sf::Color(240, 237, 237)


void Window::setWindow() {
	Button button;
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	Board board;
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), TITLE, sf::Style::Titlebar | sf::Style::Close);
	Zoom zoom;
	Color color;
	Tools tools;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			zoom.zoomEvent(event, window);

		}
		window.clear(WINDOW_COLOR);
		setViews(window, zoom.view , zoom.zooming);
		window.draw(board);
		window.draw(color);
		board.drawEvent(window , zoom.view);
		window.draw(button);
		zoom.viewMoveEvent();
		color.colorEvent(window, board.currentColor);
		window.draw(tools);
		window.display();
	}
}

void Window::setViews(sf::RenderWindow& window , sf::View boardView , bool& zooming) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	if (mousePosition.x >= 450 && mousePosition.x <= 1450) {
		if (mousePosition.y >= 20 && mousePosition.y <= 1030) {
			window.setView(boardView);
			zooming = true;
		}
	}
	else {
		window.setView(window.getDefaultView());
		zooming = false;
	}
}