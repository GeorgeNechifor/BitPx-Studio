#pragma once
#include<SFML/Graphics.hpp>

class ClickEvent
{
public:
	static bool isMouseClicked(float containerX,float containerXPlus ,float containerY , float containerYPlus , sf::RenderWindow& window);
	static bool isMouseClicked(float containerX, float containerXPlus, float containerY, float containerYPlus, sf::Vector2i mousePosition);
private:

};

