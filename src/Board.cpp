#include "../Board.h"

void Board::setBoard(sf::RenderTarget& target, sf::RenderStates states) const{
	Container container(LIGHT_GRAY, sf::Color::Transparent, sf::Vector2f(10.f, 10.f), sf::Vector2f(900.f, 100.f), 2);
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			container.setBackgroundColor(board[i][j]);
			float containerX = (j * 10) + 450;
			float containerY = (i * 10) + 20;
			container.setContainerPosition(sf::Vector2f(containerX, containerY));
			target.draw(container, states);
		}
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	setBoard(target, states);
} 

void Board::fillBoard() {
	for (short i = 0; i < 100; ++i) {
		for (short j = 0; j < 100; ++j) {
			fillBoardConditions(i, j);
		}
	}
}

void Board::hoverEvent(sf::RenderWindow& window , sf::View view) {
	
}

void Board::fillBoardConditions(short i, short j) {
	if (i % 2 == 0) {
		if (j % 2 == 0) {
			board[i][j] = DARK_GRAY;
		}
		else board[i][j] = LIGHT_GRAY;
	}
	else {
		if (j % 2 == 0) {
			board[i][j] = LIGHT_GRAY;
		}
		else board[i][j] = DARK_GRAY;
	}
}

void Board::drawEvent(sf::RenderWindow& window , sf::View view) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!isHolding) {
			isHolding = true;
		}
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f viewPos = window.mapPixelToCoords(mousePosition, view);
		for (short i = 0; i < 100; ++i) {
			for (short j = 0; j < 100; ++j) {
				float containerX = (j * 10) + 450;
				float containerY = (i * 10) + 20;
				if (viewPos.x >= containerX && viewPos.x <= containerX + 10.f) {
					if (viewPos.y >= containerY && viewPos.y <= containerY + 10.f) {
						usePixelSize(i, j);
					}
				}
			}
		}	
	}
	else {
		if (isHolding) {
			isHolding = false;
		}
	}
}

void Board::usePixelSize(short i, short j) {
	if (j >= pixelSize - 1 && i >= pixelSize - 1) {
		for (short k = i; k >= i - pixelSize + 1; k--) {
			for (short l = j; l >= j - pixelSize + 1; l--) {
				board[k][l] = currentColor;
			}
		}
	}
	else {
		if (i < pixelSize - 1) {
			short k = i;
			while (k > 0) {
				board[k][j] = currentColor;
				k--;
			}
		}
		if (j < pixelSize - 1) {
			short l = j;
			while (l > 0) {
				board[i][l] = currentColor;
				l--;
			}
		}
	}
}


void Board::eraseEvent() {
	
}