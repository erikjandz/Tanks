#pragma once
#include "stationair_grey_tank.hpp"

struct game_data {
	player_controlled_tank my_tank = player_controlled_tank();
	std::vector<enemy_tank* > enemy_tanks = {};
	std::vector<bullet* > bullets = {};
	std::vector<wall* > walls = {};
};