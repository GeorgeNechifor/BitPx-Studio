#pragma once
#include<SFML/Graphics.hpp>

class Zoom
{
public:
	Zoom() {
		setView();
	};
	void zoomEvent(sf::Event& event, sf::RenderWindow& window);
	sf::View view;
	bool zooming = false;
private:
	void setView();
};

