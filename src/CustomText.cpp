#include "../CustomText.h"
#define DEFAULT_POSITION sf::Vector2f(1.f, 1.f)
constexpr auto DEFAULT_SIZE = 20;
constexpr auto DEFAULT_STRING = "CustomText";


void CustomText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->text, states);
}

void CustomText::setTextStyle(sf::Color color, float characterSize, sf::Vector2f position, std::string text) {
	
	this->text.setFont(this->font);
	this->text.setFillColor(color);
	this->text.setCharacterSize(characterSize);
	this->text.setPosition(position);
	this->text.setString(text);
}

void CustomText::setDefaultTextStyle() {
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(DEFAULT_SIZE);
	this->text.setFont(this->font);
	this->text.setPosition(DEFAULT_POSITION);
	this->text.setString(DEFAULT_STRING);

}

void CustomText::getFont() {
	if (!this->font.loadFromFile("C:/BitPx Studio/BitPxStudio/BitPxStudio/assets/RedditSansCondensed-Medium.ttf")) {
		perror("Font not found");
	}
}

void CustomText::setTextColor(sf::Color color) {
	this->text.setFillColor(color);
}

void CustomText::setTextPosition(sf::Vector2f position) {
	this->text.setPosition(position);
}

void CustomText::setTextSize(float size) {
	this->text.setCharacterSize(size);
}

void CustomText::setTextString(std::string text) {
	this->text.setString(text);
}