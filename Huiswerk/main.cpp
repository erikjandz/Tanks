#include "player_controlled_tank.hpp"
#include <iostream>

int main() {
	auto tank = player_controlled_tank();
	std::vector<bullet *> bullets;
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	while (window.isOpen()) {
		window.display();
		sf::sleep(sf::milliseconds(20));

		window.clear(sf::Color::White);
		tank.update(window, bullets);
		//std::cout << "position = " << tank.position.x << " " << tank.position.y << "\n" << "rotation" << tank.turret_rotation << "\n";
		for (auto& bullet : bullets) {
			bullet->update();
		}
		tank.draw(window);
		for (auto& bullet : bullets) {
			bullet->draw(window);
		}

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}