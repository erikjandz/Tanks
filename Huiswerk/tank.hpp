#pragma once
#include "bullet.hpp"
#include <string>


class tank: public drawable {
public:
	//tank needs an image of the tank, an image of the turret and a position
	tank(std::string filename_vehicle, std::string filename_turret, sf::Vector2f position);

	//function that will draw all components of the tank and set the rotation and position
	void draw(sf::RenderWindow& window)override;

	virtual void update(sf::RenderWindow & window, std::vector<bullet *> & bullets) {};

	//make sure the tank doesn't drive into walls
	void interact(wall * wall);

	void interact(bullet* bullet);

protected:
	//function will rotate the turret so it will be directed to the parameter position
	void rotate_turret(sf::Vector2i point);

	//function that will create and return a bullet
	bullet* shoot();

	sf::Texture texture;
	sf::Texture texture2;
	sf::Image image;
	sf::Sprite vehicle;
	sf::Sprite turret;
	int16_t vehicle_rotation = 0;
	int16_t turret_rotation = 90;
};

