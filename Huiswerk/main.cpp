#include "player_controlled_tank.hpp"

int main() {
	auto tank = player_controlled_tank();
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	while (window.isOpen()) {
		window.display();
		sf::sleep(sf::milliseconds(20));

		window.clear();
		tank.rotate_turret(sf::Mouse::getPosition(window));
		tank.draw(window);

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}