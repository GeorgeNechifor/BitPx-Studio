#pragma once
#include<SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
	Button() {
		setDefaultButton();
	}
	void setButtonColor(sf::Color color);
	void setButtonPosition(sf::Vector2f position);
	void setButtonBorderColor(sf::Color color);
	void setButtonSize(sf::Vector2f size);
private:
	sf::RectangleShape button;
	void setDefaultButton();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(button, states);
	}
};

