#pragma once
#include "drawable.hpp"
#include <string>
#include <cmath>

class tank: public drawable {
public:
	//tank needs an image of the tank, an image of the turret and a position
	tank(std::string filename_vehicle, std::string filename_turret, sf::Vector2f position):
		drawable{position}
		{
			//load the files to sprites and set position
			texture.loadFromFile(filename_vehicle);
			vehicle.setTexture(texture);
			vehicle.setScale(sf::Vector2f(0.1, 0.1));
			vehicle.setPosition(position);
			vehicle.rotate(vehicle_rotation);
			texture2.loadFromFile(filename_turret);
			turret.setTexture(texture2);
			turret.setScale(sf::Vector2f(0.1, 0.1));
			turret.setPosition(position + sf::Vector2f{ 20, 15 });
			turret.setOrigin(sf::Vector2f{ 0, 10 });
			
		}

	void draw(sf::RenderWindow& window) override {
		window.draw(vehicle);
		turret.setRotation(turret_rotation);
		window.draw(turret);
	};

	//function will rotate the turret so it will be directed to the parameter position
	void rotate_turret(sf::Vector2i point) {
		auto deltax = point.x - turret.getPosition().x;
		auto deltay = point.x - turret.getPosition().y;
		auto angle_in_radians = atan(deltay / deltax);
		turret_rotation = angle_in_radians * 180 / 3.14159265;
	}

	sf::Texture texture;
	sf::Texture texture2;
	sf::Sprite vehicle;
	sf::Sprite turret;
	int vehicle_rotation = 0;
	int turret_rotation = 90;
};

