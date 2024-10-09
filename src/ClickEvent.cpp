#include "../ClickEvent.h"

bool ClickEvent::isMouseClicked(float containerX , float containerXPlus, float containerY, float containerYPlus, sf::RenderWindow& window) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	if (mousePosition.x >= containerX && mousePosition.x <= containerXPlus) {
		if (mousePosition.y >= containerY && mousePosition.y <= containerYPlus) {
			return true;
		}
	}
	return false;
}

bool ClickEvent::isMouseClicked(float containerX, float containerXPlus, float containerY, float containerYPlus, sf::Vector2i mousePosition) {
	if (mousePosition.x >= containerX && mousePosition.x <= containerXPlus) {
		if (mousePosition.y >= containerY && mousePosition.y <= containerYPlus) {
			return true;
		}
	}
	return false;
}