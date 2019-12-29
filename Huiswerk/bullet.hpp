#pragma once
#include "drawable.hpp"

class bullet : public drawable {
public:
	//constructor needs a position and a rotation to be properly generated
	bullet(sf::Vector2f position_tank, int16_t rotation, float speed = 2);

	void draw(sf::RenderWindow& window)override;

	void update()override;

	//calculate the starting point of a bullet
	sf::Vector2f calculate_starting_position(sf::Vector2f position_tank, int16_t rotation);

	//calculate the movement which get added to the position every update
	sf::Vector2f calculate_movement(float speed, int16_t rotation);

	sf::Vector2f movement;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
};