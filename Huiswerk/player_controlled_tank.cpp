#include "player_controlled_tank.hpp"


player_controlled_tank::player_controlled_tank():
	tank{ "player_controlled_vehicle.png", "player_controlled_turret.png", sf::Vector2f{100, 100} }
{}

void player_controlled_tank::update(sf::RenderWindow& window, std::vector<bullet*>& bullets){
	float speed = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		position.y -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			position.x += speed;
			vehicle.setRotation(-45);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			position.x -= speed;
			vehicle.setRotation(45);
		}
		else {
			vehicle.setRotation(-90);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
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
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		position.x -= speed;
		vehicle.setRotation(180);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		position.x += speed;
		vehicle.setRotation(0);
	}

	rotate_turret(sf::Mouse::getPosition(window));

	//shoot if you can
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown == 0) {
		bullets.push_back(shoot());
		cooldown = 300;
	}
	if (cooldown > 0) {
		cooldown -= 20;
	}
}