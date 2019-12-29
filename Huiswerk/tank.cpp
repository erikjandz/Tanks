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

void tank::rotate_turret(sf::Vector2i point) {
	auto deltax = point.x - turret.getPosition().x;
	auto deltay = point.y - turret.getPosition().y;
	auto angle_in_radians = atan(deltay / deltax);
	turret_rotation = angle_in_radians * 180 / 3.14159265;
	if (deltax < 0) {
		turret_rotation += 180;
	}
}

bullet* tank::shoot() {
	return new bullet(position, turret_rotation);
}