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
	float zoomLevel = 1.0f;
	const float minZoomLevel = 0.85f;
	const float maxZoomLevel = 0.3f;
	float zoomFactor = 0.9f;
	
};

