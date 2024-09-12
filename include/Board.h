#pragma once
#include<SFML/Graphics.hpp>
#include "../Container.h"

class Board : public Container
{
public:
	Board() {};
protected:
	void setBoard(sf::RenderTarget& target , sf::RenderStates states) const;
private:
	sf::Color board[100][100];
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

