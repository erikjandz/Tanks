#pragma once
#include "enemy_tank.hpp"

class stationair_grey_tank : public enemy_tank {
public:
	stationair_grey_tank(sf::Vector2f position);

	//make it rotate to the player and shoot sometimes
	void update(sf::Vector2f position_to_look_at , std::vector<bullet *> & bullets)override;
};
