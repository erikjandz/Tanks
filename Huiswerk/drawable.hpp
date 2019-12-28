#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class drawable {
public:
	drawable(sf::Vector2f position) :
		position{ position }
	{}

	virtual void draw(sf::RenderWindow& window) {};

	virtual void interact(drawable* other) {}

	virtual void update() {};

	sf::Vector2f position;
};