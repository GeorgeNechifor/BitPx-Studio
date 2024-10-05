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
	void setContainerPosition(sf::Vector2f position);
	void setContainerBorder(sf::Color color , float border);
public:
	sf::Color getBackgroundColor();
private:
	void setContainer(sf::Color color, sf::Color borderColor, sf::Vector2f size, sf::Vector2f position , float border);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RectangleShape container;

};
