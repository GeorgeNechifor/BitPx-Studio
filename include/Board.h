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
	void hoverEvent(sf::Event& event);
	void drawEvent(sf::RenderWindow& window);
	void eraseEvent();


protected:
	void setBoard(sf::RenderTarget& target , sf::RenderStates states) const;
	sf::Color currentColor = sf::Color::Black;
	unsigned short pixelSize = 10;
private:
	sf::Color board[100][100];
	bool isHolding = false;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void fillBoard();
	void fillBoardConditions(short i , short j);
	void usePixelSize(short i , short j);

};

