#include "../button.h"
#define DEFAULT_GRAY sf::Color(194, 192, 192)
#define DEFAULT_BLUE sf::Color(58, 55, 250)

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->button, states);
}

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
	this->button.setFillColor(DEFAULT_GRAY);
	this->button.setSize(sf::Vector2f(100.f, 30.f));
	this->button.setPosition(sf::Vector2f(0, 5));
	this->button.setOutlineColor(DEFAULT_BLUE);
	this->button.setOutlineThickness(1);
}

bool Button::buttonLeftClickEvent(sf::Event& event){
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			float mouseX = event.mouseButton.x;
			float mouseY = event.mouseButton.y;
			sf::Vector2f buttonCurrentPosition = this->button.getPosition();
			sf::Vector2f buttonCurrentSize = this->button.getSize();
			float marginX = buttonCurrentPosition.x + buttonCurrentSize.x;
			float marginY = buttonCurrentPosition.y + buttonCurrentSize.y;
			if (mouseX >= buttonCurrentPosition.x && mouseX <= marginX) {
				if (mouseY >= buttonCurrentPosition.y && mouseY <= marginY) {
					return true;
				}
			}
		}
	}
	return false;
}


void Button::setButtonText(std::string text) {
	this->text.setString(text);
}