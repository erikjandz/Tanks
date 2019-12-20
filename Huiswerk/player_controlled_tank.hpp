#pragma once
#include "tank.hpp"

class player_controlled_tank : public tank {
public:
	player_controlled_tank():
		tank{ "player_controlled_vehicle.png", "player_controlled_turret.png", sf::Vector2f{10, 10} }
		{}


};