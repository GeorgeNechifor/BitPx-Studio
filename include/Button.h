#pragma once
#include <SFML/Graphics.hpp>
#include "../CustomText.h"

class Button : public CustomText
{
public:
	Button() {
		setDefaultButton();
	};

	void setButtonColor(sf::Color color);
	void setButtonPosition(sf::Vector2f position);
	void setButtonBorderColor(sf::Color color);
	void setButtonSize(sf::Vector2f size);
	void setButtonText(std::string text);
	bool buttonLeftClickEvent(sf::Event& event);
private:
	sf::RectangleShape button;
	sf::Text text;
	void setDefaultButton();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

