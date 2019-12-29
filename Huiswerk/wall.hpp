#pragma once
#include "drawable.hpp"

class wall : public drawable {
public:
	wall(sf::Vector2f position);

	void draw(sf::RenderWindow& window)override;

	sf::Texture texture;
	sf::Sprite sprite;
};
