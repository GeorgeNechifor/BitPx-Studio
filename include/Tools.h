#pragma once
#include<SFML/Graphics.hpp>
#include"../Container.h"
#include"../CustomText.h"
#include"../Button.h"
#include"../ClickEvent.h"

class Tools : public sf::Drawable
{
public:
	void setTools(sf::RenderTarget& target , sf::RenderStates states) const;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

