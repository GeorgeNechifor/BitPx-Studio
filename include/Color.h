#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"../Container.h"
#include"../Board.h"
#include "../CustomText.h"
class Color : public sf::Drawable
{
public:
	Color() { fillColors(); };
	void colorEvent(sf::RenderWindow& window , sf::Color& currentColor);
	void RGBEvent(sf::RenderWindow& window , sf::Event& event);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setColorContainer(sf::RenderTarget& target, sf::RenderStates states) const;
	void setRGBColor(sf::RenderTarget& target, sf::RenderStates states) const;
	void fillColors();
	void setKeyboardInput(int input);
	int isMouseLeft(sf::RenderWindow& window);
private:
	sf::Color colors[4][4];
	short col = 0, row = 0;
	short RGB[3] = { 0,0,0 };
	short keyboardInput = 0;
};

