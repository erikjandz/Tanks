#include "stationair_grey_tank.hpp"

stationair_grey_tank::stationair_grey_tank(sf::Vector2f position) :
	enemy_tank{ "stationair_grey_vehicle.png", "stationair_grey_turret.png", position }
{}

void stationair_grey_tank::update(sf::Vector2f position_to_look_at, std::vector<bullet *> &bullets) {
	rotate_turret(position_to_look_at);
	if (rand() % 100 == 0) {
		bullets.push_back(shoot());
	}
}