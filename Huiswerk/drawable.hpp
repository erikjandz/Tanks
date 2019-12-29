#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>



class drawable {
public:
	drawable(sf::Vector2f position);

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void interact(drawable* other) {}

	virtual void update() {}

	sf::Vector2f position;
};