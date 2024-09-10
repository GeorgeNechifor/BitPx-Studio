#pragma once
#include<SFML/Graphics.hpp>

class CustomText : public sf::Drawable
{
public:
	CustomText(sf::Color color , float characterSize , sf::Vector2f position , std::string text) {

	}

private:
	sf::Text text;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextStyle(sf::Color, float characterSize, sf::Vector2f position, std::string text);

};

