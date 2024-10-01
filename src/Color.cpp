#include "../Color.h"


void Color::setColorContainer(sf::RenderTarget& target, sf::RenderStates states) const {
	Container container(sf::Color::Black, sf::Color::Transparent, sf::Vector2f(70.f, 70.f), sf::Vector2f(900.f, 100.f), 2);
	for (short i = 0; i < 4; ++i) {
		for (short j = 0; j < 4; ++j) {
			container.setBackgroundColor(colors[i][j]);
			float containerX = (j * 73) + 1505;
			float containerY = (i * 73) + 720;
			container.setContainerPosition(sf::Vector2f(containerX, containerY));
			target.draw(container, states);
			if (i == this->row && j == this->col) {
				container.setContainerBorder(sf::Color::Black, 3);
			}
			else {
				container.setContainerBorder(sf::Color::Transparent, 3);
			}
		}
	}
}


void Color::fillColors() {
	std::vector<sf::Color> colorList = { sf::Color(255, 0, 0), sf::Color(0 , 0 , 0) , sf::Color(0, 0, 255) , sf::Color(255, 87, 98),
										sf::Color(0, 255, 0), sf::Color(255, 255, 0), sf::Color(255, 255, 255), sf::Color(105, 255, 120),
										sf::Color(220, 3, 255),sf::Color(3, 179, 255) , sf::Color(255, 159, 5), sf::Color(153, 156, 247),
										sf::Color(37, 92, 20),sf::Color(3, 255, 133) , sf::Color(92, 26, 20) , sf::Color(252, 93, 247)};
	short ind = 0;
	for (short i = 0; i < 4; ++i) {
		for (short j = 0; j < 4; ++j) {
			colors[i][j] = colorList[ind];
			ind++;
		}
	}
}

void Color::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	setColorContainer(target, states);
}

void Color::colorEvent(sf::RenderWindow& window , sf::Color& currentColor) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (short i = 0; i < 4; ++i) {
			for (short j = 0; j < 4; ++j) {
				float containerX = (j * 73) + 1505;
				float containerY = (i * 73) + 720;
				if (mousePos.x > containerX && mousePos.x < containerX + 120) {
					if (mousePos.y > containerY && mousePos.y < containerY + 100) {
						currentColor = colors[i][j];
						row = i, col = j;
						std::cout << i << " " << j << std::endl;
					}
				}
			}
		}
	}
}
