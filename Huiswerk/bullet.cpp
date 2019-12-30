#include "bullet.hpp"

bullet::bullet(sf::Vector2f position_tank, int16_t rotation, float speed, int8_t bounce):
	drawable{ calculate_starting_position(position_tank, rotation) },
	bounce{bounce}
{
	image.loadFromFile("bullet.png");
	image.createMaskFromColor(sf::Color::White, 0);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.1, 0.1));
	sprite.setOrigin(sf::Vector2f{ 0, 25 });
	sprite.setPosition(position);
	sprite.setRotation(rotation);
	movement = calculate_movement(speed, rotation);
}

void bullet::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

void bullet::update() {
	position += movement;
	sprite.setPosition(position);
}

void bullet::interact(wall* wall) {
	if (sprite.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
		float differencex = position.x - wall->position.x;
		float differencey = position.y - wall->position.y;
		if (differencex < 0) {
			differencex *= -1;
		}
		if (differencey < 0) {
			differencey *= -1;
		}
		//if the bullet bounces left or right
		if (differencex - 1 > differencey) {
			movement.x *= -1;
			sprite.setRotation(sprite.getRotation() * -1 + 180);
			bounce -= 1;
		//if the bullet bounces top or bottom
		}else if (differencex < differencey - 1) {
			movement.y *= -1;
			sprite.setRotation(sprite.getRotation() * -1);
			bounce -= 1;
		//if it hits a corner
		}else {
			bounce = -1;
		}

		if (bounce <= -1) {
			death_flag = true;
		}
	}
}

void bullet::interact(bullet* bullet) {
	if (sprite.getGlobalBounds().intersects(bullet->sprite.getGlobalBounds())) {
		death_flag = true;
		bullet->death_flag = true;

	}
}

sf::Vector2f bullet::calculate_starting_position(sf::Vector2f position_tank, int16_t rotation) {
	float length_turret = 32.5;
	float positionx = cos(rotation * 3.14159265 / 180) * length_turret;
	float positiony = sin(rotation * 3.14159265 / 180) * length_turret;
	return position_tank + sf::Vector2f{ positionx, positiony };
}

sf::Vector2f bullet::calculate_movement(float speed, int16_t rotation) {
	return sf::Vector2f(cos(rotation * 3.14159265 / 180) * speed, sin(rotation * 3.14159265 / 180) * speed);
}