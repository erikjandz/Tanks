#pragma once
#include "wall.hpp"

class bullet : public drawable {
public:
	//constructor needs a position and a rotation to be properly generated
	bullet(sf::Vector2f position_tank, int16_t rotation, float speed = 3, int8_t bounce = 1);

	void draw(sf::RenderWindow& window)override;

	void update()override;

	void interact(wall* wall);

	void interact(bullet* bullet);

	sf::Vector2f movement;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;

private:
	//calculate the starting point of a bullet
	sf::Vector2f calculate_starting_position(sf::Vector2f position_tank, int16_t rotation);

	//calculate the movement which get added to the position every update
	sf::Vector2f calculate_movement(float speed, int16_t rotation);
	int8_t bounce;
	

};