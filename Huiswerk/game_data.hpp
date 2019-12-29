#pragma once
#include "player_controlled_tank.hpp"

struct game_data {
	player_controlled_tank my_tank = player_controlled_tank();
	std::vector<bullet* > bullets = {};
	std::vector<wall*> walls = {};
};