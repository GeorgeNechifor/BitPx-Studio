#pragma once
#include<SFML/Graphics.hpp>
#include"../Board.h"
constexpr auto TITLE = "BitPx Studio";

class Window
{
public:
	void setWindow();
private:
	void setViews(sf::RenderWindow& window , sf::View boardView , bool& zooming);
	
};

