#include "../Color.h"

#define DARK_GRAY sf::Color(160, 160, 160)
#define LIGHT_GRAY sf::Color(210, 210, 210)


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
				container.setContainerBorder(DARK_GRAY, 3);
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
	setCustomColor(target, states);
}

void Color::colorEvent(sf::RenderWindow& window , sf::Color& currentColor) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (short i = 0; i < 4; ++i) {
			for (short j = 0; j < 4; ++j) {
				float containerX = ((float)j * 73) + 1505;
				float containerY = ((float)i * 73) + 730;
				if (ClickEvent::isMouseClicked(containerX, containerX + 120, containerY, containerY + 120, window)) {
					currentColor = colors[i][j];
					row = i, col = j;
				}
			}
		}
	}
}


void Color::setCustomColor(sf::RenderTarget& target, sf::RenderStates states) const {
	Container container(sf::Color::Transparent, DARK_GRAY, sf::Vector2f(215.f, 30.f), sf::Vector2f(1505.f, 690.f), 2);
	Container valueContainer(LIGHT_GRAY, DARK_GRAY, sf::Vector2f(71.6, 30.f), sf::Vector2f(1505.f, 690.f), 2);
	CustomText rgbText(sf::Color::Black, 15, sf::Vector2f(0, 0), "t");
	
	for (int i = 0; i < 4; ++i) {
		if (i == 3) {
			valueContainer.setBackgroundColor(sf::Color(RGB[0] , RGB[1] , RGB[2]));
			valueContainer.setContainerPosition(sf::Vector2f(1505.f + (i * 71.6), 690.f));
			target.draw(valueContainer, states);
		}
		else {
			rgbText.setTextString(std::to_string(RGB[i]));
			rgbText.setTextPosition(sf::Vector2f(1505.f + (i * 80), 700.f));
			valueContainer.setContainerPosition(sf::Vector2f(1505.f + (i * 71.6), 690.f));
			this->customColorEvent(valueContainer, 1505.f + (i * 71.6), 690.f);
			target.draw(valueContainer, states);
			target.draw(rgbText, states);
		}
	}

	target.draw(container, states);
	float containerX = 1505.f;
	float containerY = 690.f;
}

void Color::centerText(CustomText& text, Container& container) {
	sf::FloatRect textBounds = text.getBounds();
	sf::FloatRect buttonBounds = container.getBounds();
	float textX = (buttonBounds.width / 2.f) - (textBounds.width / 2.f) - 0.5;
	float textY = (buttonBounds.height / 2.f) - (textBounds.height / 2.f) - 0.5;
	text.setTextPosition(sf::Vector2f(textX, textY));
}

void Color::customColorEvent(Container& container, float containerX, float containerY) const {
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (ClickEvent::isMouseClicked(containerX, containerX + 71.6, containerY, containerY + 71.6, mousePosition)) {
			container.setBackgroundColor(DARK_GRAY);
			
		}
		else {
			container.setBackgroundColor(LIGHT_GRAY);
		}
	}	
}

void Color::rgbScrollEvent(sf::Event& event, sf::Color& currentColor, sf::RenderWindow& window) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	if (mousePosition.x < 450 || mousePosition.x > 1450) {
		if (mousePosition.y < 20 || mousePosition.y > 800) {
			if (event.type == sf::Event::MouseWheelScrolled) {
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					int delta = event.mouseWheelScroll.delta;
					if (delta >= 0) {
						if (this->input > 0) {
							this->input--;
						}
					}
					else if (delta <= 0) {
						if (this->input < 255) {
							this->input++;
						}
					}
					this->RGB[1] = input;
					currentColor = sf::Color(this->RGB[1], this->RGB[1], this->RGB[2]);
				}
			}
		}
	}
}
