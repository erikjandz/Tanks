#include "game_data.hpp"
#include <iostream>

//update the game
void update(sf::RenderWindow& window, game_data& game_data1) {
	game_data1.my_tank.update(window, game_data1.bullets);
	//std::cout << "position = " << tank.position.x << " " << tank.position.y << "\n" << "rotation" << tank.turret_rotation << "\n";
	for (auto& bullet : game_data1.bullets) {
		bullet->update();
	}
}

//render the game
void render(sf::RenderWindow& window, game_data& game_data1){
	game_data1.my_tank.draw(window);
	for (auto& bullet : game_data1.bullets) {
		bullet->draw(window);
	}
}

int main() {
	game_data game_data1 = game_data();
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	while (window.isOpen()) {
		window.display();
		sf::sleep(sf::milliseconds(20));

		window.clear(sf::Color::White);
		update(window, game_data1);
		render(window, game_data1);

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}