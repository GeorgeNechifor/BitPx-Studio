#include "../Color.h"


void Color::setColorContainer(sf::RenderTarget& target, sf::RenderStates states) const {
	Container container(sf::Color::Black, sf::Color::Transparent, sf::Vector2f(120.f, 100.f), sf::Vector2f(900.f, 100.f), 2);
	for (short i = 0; i < 3; ++i) {
		for (short j = 0; j < 3; ++j) {
			container.setBackgroundColor(colors[i][j]);
			float containerX = (j * 120) + 1505;
			float containerY = (i * 100) + 720;
			container.setContainerPosition(sf::Vector2f(containerX, containerY));
			target.draw(container, states);
		}
	}
}


void Color::fillColors() {
	std::vector<sf::Color> colorList = {sf::Color(255, 0, 0), sf::Color(0 , 0 , 0) , sf::Color(0, 0, 255) , 
										sf::Color(0, 255, 0), sf::Color(255, 255, 0), sf::Color(255, 255, 255),
										sf::Color(220, 3, 255),sf::Color(3, 179, 255) , sf::Color(255, 159, 5)};
	short ind = 0;
	for (short i = 0; i < 3; ++i) {
		for (short j = 0; j < 3; ++j) {
			colors[i][j] = colorList[ind];
			ind++;
		}
	}
}

void Color::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	setColorContainer(target, states);
}

void Color::colorEvent() {

}