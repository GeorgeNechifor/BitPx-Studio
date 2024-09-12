#pragma once
#include<SFML/Graphics.hpp>
class Container : public sf::Drawable
{
public:
	Container(sf::Color color, sf::Color  borderColor, sf::Vector2f size, sf::Vector2f position , float border) {
		setContainer(color, borderColor, size, position , border);
	};
	Container() {};
	void setBackgroundColor(sf::Color color);
private:
	void setContainer(sf::Color color, sf::Color borderColor, sf::Vector2f size, sf::Vector2f position , float border);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape container;

};

