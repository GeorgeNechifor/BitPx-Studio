#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class CustomText : public sf::Drawable
{
public:
	CustomText(sf::Color color, float characterSize, sf::Vector2f position, std::string text) {
		getFont();
		setTextStyle(color, characterSize, position, text);
		
	};
	CustomText() { 
		getFont();
		setDefaultTextStyle();
		
	};
	void setTextString(std::string text);
	void setTextPosition(sf::Vector2f position);
	void setTextSize(float size);
	void setTextColor(sf::Color color);
	sf::FloatRect getBounds();
protected:
	sf::Text text;

private:
	sf::Font font;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextStyle(sf::Color, float characterSize, sf::Vector2f position, std::string text);
	void setDefaultTextStyle();
	void getFont();
};

