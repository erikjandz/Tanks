#pragma once
#include "drawable.hpp"

class bullet : public drawable {
public:
	//constructor needs a position and a rotation to be properly generated
	bullet(sf::Vector2f position_tank, int16_t rotation, float speed = 2):
		drawable{ calculate_starting_position(position_tank, rotation)}
	{
		image.loadFromFile("bullet.png");
		image.createMaskFromColor(sf::Color::White, 0);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.1, 0.1));
		sprite.setOrigin(sf::Vector2f{ 0, 50 });
		sprite.setPosition(position);
		sprite.setRotation(rotation);
		movement = calculate_movement(speed, rotation);
	}

	void draw(sf::RenderWindow & window)override{
		window.draw(sprite);
	}

	void update()override {
		position += movement;
		sprite.setPosition(position);
	}

	//calculate the starting point of a bullet
	sf::Vector2f calculate_starting_position(sf::Vector2f position_tank, int16_t rotation){
		float length_turret = 32.5;
		float positionx = cos(rotation * 3.14159265 / 180) * length_turret;
		float positiony = sin(rotation * 3.14159265 / 180) * length_turret;
		return position_tank + sf::Vector2f{ positionx, positiony };
	}

	//calculate the movement which get added to the position every update
	sf::Vector2f calculate_movement(float speed, int16_t rotation) {
		return sf::Vector2f(cos(rotation * 3.14159265 / 180) * speed, sin(rotation * 3.14159265 / 180) * speed);
	}

	sf::Vector2f movement;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
};