#pragma once
#include "tank.hpp"

class player_controlled_tank : public tank {
public:
	player_controlled_tank():
		tank{ "player_controlled_vehicle.png", "player_controlled_turret.png", sf::Vector2f{100, 100} }
		{}

	//this function updates the position of the tank and the rotation 
	void update(sf::RenderWindow & window) override{
		float speed = 1.5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			position.y -= speed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				position.x += speed;
				vehicle.setRotation(-45);
			}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				position.x -= speed;
				vehicle.setRotation(45);
			}else {
				vehicle.setRotation(-90);
			}
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			position.y += speed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				position.x += speed;
				vehicle.setRotation(45);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				position.x -= speed;
				vehicle.setRotation(-45);
			}
			else {
				vehicle.setRotation(90);
			}
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			position.x -= speed;
			vehicle.setRotation(180);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			position.x += speed;
			vehicle.setRotation(0);
		}
		rotate_turret(sf::Mouse::getPosition(window));
	}

};