#include "tank.hpp"

tank::tank(std::string filename_vehicle, std::string filename_turret, sf::Vector2f position):
	drawable{ position }
{
	//load the files to sprites and set position
	texture.loadFromFile(filename_vehicle);
	vehicle.setTexture(texture);
	vehicle.setScale(sf::Vector2f(0.1, 0.1));
	vehicle.setOrigin(sf::Vector2f{ 200, 150 });
	vehicle.setPosition(position);

	image.loadFromFile(filename_turret);
	image.createMaskFromColor(sf::Color::White, 0);
	texture2.loadFromImage(image);
	turret.setTexture(texture2);
	turret.setScale(sf::Vector2f(0.1, 0.1));
	turret.setOrigin(sf::Vector2f{ 100, 100 });
	turret.setPosition(position);

}

void tank::draw(sf::RenderWindow& window){
	vehicle.setPosition(position);
	window.draw(vehicle);
	turret.setPosition(position);
	turret.setRotation(turret_rotation);
	window.draw(turret);
};

void tank::interact(wall * wall){
	if (vehicle.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
		float differencex = position.x - wall->position.x;
		float differencey = position.y - wall->position.y;
		//tank is right of wall
		if (differencex >= differencey && differencex >= differencey * -1) {
			while (vehicle.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
				position.x ++;
				vehicle.setPosition(position);
			}
		}
		//tank is left of wall
		else if (differencex <= differencey && differencex <= differencey * -1) {
			while (vehicle.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
				position.x --;
				vehicle.setPosition(position);
			}
		}
		//tank is on top of wall
		else if (differencey < differencex && differencey < differencex * -1) {
			while (vehicle.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
				position.y --;
				vehicle.setPosition(position);
			}
		}
		//tank is under the wall
		else if (differencey > differencex && differencey > differencex * -1) {
			while (vehicle.getGlobalBounds().intersects(wall->sprite.getGlobalBounds())) {
				position.y ++;
				vehicle.setPosition(position);
			}
		}
	}
}

void tank::interact(bullet* bullet) {
	if (vehicle.getGlobalBounds().intersects(bullet->sprite.getGlobalBounds())) {
		bullet->death_flag = true;
		death_flag = true;
	}
}

void tank::rotate_turret(sf::Vector2f position_to_look_at) {
	float deltax = position_to_look_at.x - turret.getPosition().x;
	float deltay = position_to_look_at.y - turret.getPosition().y;
	auto angle_in_radians = atan(deltay / deltax);
	turret_rotation = angle_in_radians * 180 / 3.14159265;
	//atan always returns between -90 and 90 so if we want to rotate left we have to rotate 180 more
	if (deltax < 0) {
		turret_rotation += 180;
	}
}

bullet* tank::shoot() {
	return new bullet(position, turret_rotation);
}