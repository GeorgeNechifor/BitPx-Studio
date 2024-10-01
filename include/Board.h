#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "../Container.h"
#define LIGHT_GRAY sf::Color(210, 210, 210)
#define DARK_GRAY sf::Color(160, 160, 160)
#define HOVER_COLOR sf::Color::Black;

class Board : public Container
{
public:
	Board() {
		fillBoard();
	};
	void hoverEvent(sf::RenderWindow& window , sf::View view);
	void drawEvent(sf::RenderWindow& window , sf::View view);
	void eraseEvent();
	sf::Color currentColor = sf::Color::Black;
protected:
	void setBoard(sf::RenderTarget& target , sf::RenderStates states) const;
	unsigned short pixelSize = 3;
private:
	sf::Color board[100][100];
	bool isHolding = false;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void fillBoard();
	void fillBoardConditions(short i , short j);
	void usePixelSize(short i , short j);

};

