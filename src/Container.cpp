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

void Container::setContainerPosition(sf::Vector2f position) {
	this->container.setPosition(position);
}

sf::Color Container::getBackgroundColor() {
	return this->container.getFillColor();
}


void Container::setContainerBorder(sf::Color color , float border) {
	this->container.setOutlineColor(color);
	this->container.setOutlineThickness(border);
}