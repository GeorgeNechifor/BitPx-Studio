#include "../Zoom.h"
#include<iostream>

void Zoom::zoomEvent(sf::Event& event, sf::RenderWindow& window) {
	if (zooming) {
		if (event.type == sf::Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
				int delta = event.mouseWheelScroll.delta;
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);
				if (this->view.getSize().x != 1010 && this->view.getSize().y != 1010) {
					zoomed = true;
				}
				else {
					zoomed = false;
				}
				if (delta >= 0) { //zoom in
					if (zoomLevel / zoomFactor >= maxZoomLevel) {
						zoomLevel *= zoomFactor;

					}
				}
				else if (delta <= 0) { //zoom out
					if (zoomLevel * zoomFactor <= minZoomLevel) {
						zoomLevel /= zoomFactor;

					}
				}
				sf::Vector2f boardSize(1010.f, 1010.f);
				sf::Vector2f boardPosition(450.f, 20.f);
				this->view.setSize(sf::Vector2f(1010.f, 1010.f) * zoomLevel);
				this->view.setCenter(boardPosition + boardSize / 2.f);
				std::cout << zoomLevel * 100 << std::endl;
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

void Zoom::viewMoveEvent() {
	float moveSpaceX = 1010 - this->view.getSize().x;
	float viewX = this->view.getCenter().x - (this->view.getSize().x / 2.f);
	float viewY = this->view.getCenter().y - (this->view.getSize().y / 2.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (viewX >= 450 && viewX < 1010) {
			this->view.move(5.f, 0.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (viewX > 450) {
			this->view.move(-5.f, 0.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (viewY > 20 && viewY < 450) {
			this->view.move(0.f, 5.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (viewY > 20) {
			this->view.move(0.f, -5.f);
		}
	}
}