#include "../Color.h"


void Color::setColorContainer(sf::RenderTarget& target, sf::RenderStates states) const {
	Container container(sf::Color::Black, sf::Color::Transparent, sf::Vector2f(70.f, 70.f), sf::Vector2f(900.f, 100.f), 2);
	for (short i = 0; i < 4; ++i) {
		for (short j = 0; j < 4; ++j) {
			container.setBackgroundColor(colors[i][j]);
			float containerX = (j * 73) + 1505;
			float containerY = (i * 73) + 730;
			container.setContainerPosition(sf::Vector2f(containerX, containerY));
			target.draw(container, states);
			if (i == this->row && j == this->col - 1) {
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
	setRGBColor(target, states);
}

void Color::colorEvent(sf::RenderWindow& window , sf::Color& currentColor) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (short i = 0; i < 4; ++i) {
			for (short j = 0; j < 4; ++j) {
				float containerX = ((float)j * 73) + 1505;
				float containerY = ((float)i * 73) + 730;
				if (mousePos.x > containerX && mousePos.x < containerX + 120) {
					if (mousePos.y > containerY && mousePos.y < containerY + 100) {
						currentColor = colors[i][j];
						row = i, col = j;
					}
				}
			}
		}
	}
}


void Color::setRGBColor(sf::RenderTarget& target, sf::RenderStates states) const {
	Container container(sf::Color::Transparent, sf::Color::Black, sf::Vector2f(70.f, 70.f), sf::Vector2f(1605.f, 700.f), 2);
	CustomText rgbText(sf::Color::Black, 20, sf::Vector2f(0, 0), "t");
	CustomText rgbValues(sf::Color::Black, 20, sf::Vector2f(0, 0), "t");
	float containerX = 0, containerY = 650;
	std::string text[3] = { "R","G","B" };
	for (short i = 0; i < 3; ++i) {
		containerX = ((float)i * 107) + 1505;
		rgbText.setTextPosition(sf::Vector2f(containerX + 31, 620));
		rgbText.setTextString(text[i]);
		rgbValues.setTextString(std::to_string(this->RGB[i]));
		rgbValues.setTextPosition(sf::Vector2f(containerX + 31, 675));
		container.setContainerPosition(sf::Vector2f(containerX, containerY));
		target.draw(container, states);
		target.draw(rgbText, states);
		target.draw(rgbValues, states);
	}
}

void Color::RGBEvent(sf::RenderWindow& window , sf::Event& event) {
	int result = this->isMouseLeft(window);
	std::cout << result << " " << std::endl;
	if (result != -1) {
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode >= 49 && event.text.unicode <= 57) {
					int input = (event.text.unicode % 10) + 2;
					if (this->keyboardInput <= 255 && this->keyboardInput >= 0) {
						setKeyboardInput(input);
						RGB[result] = this->keyboardInput;
				}
			}
		}
	}
}

void Color::setKeyboardInput(int input) {
	if (input > 0) {
		this->keyboardInput *= 10;
		this->keyboardInput += input;
	}
	this->keyboardInput *= 10;
}

int Color::isMouseLeft(sf::RenderWindow& window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (short i = 0; i < 3; ++i) {
			float containerX = ((float)i * 107) + 1505;
			float containerY = 620;
			if (mousePos.x >= containerX && mousePos.x <= containerX + 70.f) {
				if (mousePos.y > containerY && mousePos.y <= containerY + 70.f) {
					return i;
				}
				else {
					return -1;
				}
			}
			
		}
	}
	
}