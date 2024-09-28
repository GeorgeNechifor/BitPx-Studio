#pragma once
#include<SFML/Graphics.hpp>

class Zoom
{
public:
	Zoom() {
		setView();
	};
	void zoomEvent(sf::Event& event, sf::RenderWindow& window);
	void viewMoveEvent();
	sf::View view;
	bool zooming = false;
	float zoomLevel = 1.0f;

private:
	void setView();
	const float minZoomLevel = 0.85f;
	const float maxZoomLevel = 0.3f;
	float zoomFactor = 0.9f;	
	bool zoomed = false;
};

