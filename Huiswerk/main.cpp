#include "game_data.hpp"
#include <iostream>

//update the game
void update(sf::RenderWindow& window, game_data& game_data1) {
	//make the player_controlled_tank move
	game_data1.my_tank.update(window, game_data1.bullets);
	for (auto & wall : game_data1.walls) {
		game_data1.my_tank.interact(wall);
	}
	//let the bullets move
	for (auto& bullet : game_data1.bullets) {
		bullet->update();
	}
	//make sure the bullets bounce or get killed
	for (auto& bullet : game_data1.bullets) {
		for (auto& wall : game_data1.walls) {
			bullet->interact(wall);
		}
	}


}

//render the game
void render(sf::RenderWindow& window, game_data& game_data1){
	//draw the player's tank
	game_data1.my_tank.draw(window);
	//draw the bullets
	for (auto& bullet : game_data1.bullets) {
		bullet->draw(window);
	}
	//draw the walls
	for (auto& wall : game_data1.walls) {
		wall->draw(window);
	}

}

int main() {
	game_data game_data1 = game_data();
	game_data1.walls.push_back(new wall{ sf::Vector2f{ 100,100 } });
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	while (window.isOpen()) {
		window.display();
		sf::sleep(sf::milliseconds(20));

		window.clear();
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