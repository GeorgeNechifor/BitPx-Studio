#include "../Board.h"

void Board::setBoard(sf::RenderTarget& target, sf::RenderStates states) const{
	Container container(sf::Color::Black, sf::Color::Green, sf::Vector2f(100.f, 100.f), sf::Vector2f(300.f, 300.f), 2);
	target.draw(container, states);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	setBoard(target, states);
}