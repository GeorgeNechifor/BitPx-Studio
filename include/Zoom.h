#pragma once
#include<SFML/Graphics.hpp>

class Zoom
{
public:
	void zoomEvent(sf::Event& event, sf::RenderWindow& window);
	sf::View view;
private:
	float zoomFactor = 1;
};

