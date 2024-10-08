#include "../Image.h"


void Image::setImagePosition(sf::Vector2f position) {
	this->sprite.setPosition(position);
}

void Image::setImageScale(sf::Vector2f scale) {
	this->sprite.setScale(scale);
}

void Image::setImageTexture(std::string textureAdress) {
	this->texture.loadFromFile(textureAdress);
	this->sprite.setTexture(this->texture);
}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->sprite, states);
}