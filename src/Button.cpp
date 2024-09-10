#include "../button.h"

void Button::setButtonColor(sf::Color color) {
	this->button.setFillColor(color);
}

void Button::setButtonSize(sf::Vector2f size) {
	this->button.setSize(size);
}

void Button::setButtonPosition(sf::Vector2f position) {
	this->button.setPosition(position);
}

void Button::setButtonBorderColor(sf::Color color) {
	this->button.setOutlineColor(color);
}

void Button::setDefaultButton() {
	button.setFillColor(sf::Color::Black);
	button.setSize(sf::Vector2f(100.f, 30.f));
	button.setPosition(sf::Vector2f(0, 0));
}

