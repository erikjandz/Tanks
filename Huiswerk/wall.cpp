#include "wall.hpp"

wall::wall(sf::Vector2f position):
	drawable{position}
	{
		texture.loadFromFile("wall.png");
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.1, 0.1));
		sprite.setOrigin(sf::Vector2f{ 200,200 });
		sprite.setPosition(position);
	}

void wall::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}