#pragma once
#include "tank.hpp"

class player_controlled_tank : public tank {
public:
	player_controlled_tank();

	//this function updates the position of the tank and the rotation 
	void update(sf::RenderWindow& window, std::vector<bullet*>& bullets)override;

	int cooldown = 0;
};