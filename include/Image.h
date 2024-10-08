#pragma once
#include<SFML/Graphics.hpp>

class Image : public sf::Drawable
{
public:
	Image(sf::Vector2f scale , sf::Vector2f position , std::string textureAdress) {
		this->setImagePosition(position);
		this->setImageScale(scale);
		this->setImageTexture(textureAdress);
	};
	void setImagePosition(sf::Vector2f position);
	void setImageScale(sf::Vector2f scale);
private:
	void setImageTexture(std::string textureAdress);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

