#pragma once
#include <SFML/Graphics.hpp>
#include "../CustomText.h"
#include"../ClickEvent.h"

class Button : public sf::Drawable
{
public:
	Button() {
		setDefaultButton();
		centerText();
	};

	void setButtonColor(sf::Color color);
	void setButtonPosition(sf::Vector2f position);
	void setButtonBorderColor(sf::Color color);
	void setButtonSize(sf::Vector2f size);
	void setButtonText(std::string text);
	bool buttonLeftClickEvent(sf::Event& event);
private:
	sf::RectangleShape button;
	sf::Text buttonText;
	sf::Font font;
	void setDefaultButton();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void centerText();
};

