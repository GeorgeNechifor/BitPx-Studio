#include "../Zoom.h"
#include<iostream>


void Zoom::zoomEvent(sf::Event& event, sf::RenderWindow& window) {
	if (zooming) {
		if (event.type == sf::Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
				int delta = event.mouseWheelScroll.delta;
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);
				if (delta >= 0) {
					if (zoomLevel / zoomFactor >= maxZoomLevel) {
						zoomLevel *= zoomFactor;
					}
				}
				else if (delta <= 0) {
					if (zoomLevel * zoomFactor <= minZoomLevel) {
						zoomLevel /= zoomFactor;
					}
				}
				this->view.setSize(sf::Vector2f(1010.f, 1010.f) * zoomLevel);
			}
		}

		else {
			this->view.zoom(1.f);
		}
	}
}

void Zoom::setView() {
	sf::Vector2f boardSize(1010.f, 1010.f);
	sf::Vector2f boardPosition(450.f, 20.f);
	this->view.setSize(boardSize);
	this->view.setCenter(boardPosition + boardSize / 2.f);
	float winWidth = 1920;
	float winHeight = 1080;
	this->view.setViewport(sf::FloatRect(boardPosition.x / winWidth, boardPosition.y / winHeight, boardSize.x / winWidth, boardSize.y / winHeight));
}