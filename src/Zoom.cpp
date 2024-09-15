#include "../Zoom.h"
#include<iostream>


void Zoom::zoomEvent(sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
			int delta = event.mouseWheelScroll.delta;
			std::cout << delta << std::endl;
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
			if(mousePos.x > 450 && mousePos.x < 1440 && mousePos.y > 10 && mousePos.y < 1010){
				view.setCenter(worldPos);
				if (delta > 0) {
					view.zoom(0.9f);
				}
				else {
					view.zoom(1.1f);
				}
			}
				
		}
	}
}