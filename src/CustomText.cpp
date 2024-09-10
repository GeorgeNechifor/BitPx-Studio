#include "../CustomText.h"

void CustomText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->text, states);
}

void CustomText::setTextStyle(sf::Color color, float characterSize, sf::Vector2f position, std::string text) {
	this->text.setFillColor(color);
	this->text.setCharacterSize(characterSize);
	this->text.setPosition(position);
	this->text.setString(text);
}