#pragma once
#include "player_controlled_tank.hpp"

class enemy_tank : public tank {
public:
	enemy_tank(std::string filename_vehicle, std::string filename_turret, sf::Vector2f position) :
		tank{ filename_vehicle, filename_turret, position }
		{}

	virtual void update(sf::Vector2f position_to_look_at, std::vector<bullet *> & bullets) {};

};
