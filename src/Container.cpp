#include "../Container.h"


void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->container);
}

void Container::setContainer(sf::Color color, sf::Color borderColor, sf::Vector2f size, sf::Vector2f position , float border) {
	this->container.setFillColor(color);
	this->container.setOutlineColor(borderColor);
	this->container.setPosition(position);
	this->container.setSize(size);
	this->container.setOutlineThickness(border);
}

void Container::setBackgroundColor(sf::Color color) {
	this->container.setFillColor(color);
}