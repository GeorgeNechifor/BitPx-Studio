#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"../Container.h"
#include"../Board.h"
#include "../CustomText.h"
#include"../ClickEvent.h"

class Color : public sf::Drawable
{
public:
	Color() { fillColors(); };
	void colorEvent(sf::RenderWindow& window , sf::Color& currentColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setColorContainer(sf::RenderTarget& target, sf::RenderStates states) const;
	void fillColors();
	void setCustomColor(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Color colors[4][4];
	short col = 0, row = 0;
	int RGB[3] = { 0,0,0};
	int keyboardInput = 0;
};

