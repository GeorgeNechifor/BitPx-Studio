#include "../Tools.h"
#define DARK_GRAY sf::Color(160, 160, 160)


void Tools::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	setTools(target, states);
}

void Tools::setTools(sf::RenderTarget& target , sf::RenderStates states) const {
	Container toolsContainer(sf::Color::Transparent,DARK_GRAY , sf::Vector2f(200.f, 500.f), sf::Vector2f(20.f, 60.f), 2);
	target.draw(toolsContainer, states);
	
}