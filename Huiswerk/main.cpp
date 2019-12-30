#include "game_data.hpp"
#include <iostream>
#include <algorithm>

//update the game
void update(sf::RenderWindow& window, game_data& game_data1) {
	//make the player_controlled_tank move
	game_data1.my_tank.update(window, game_data1.bullets);
	//make sure the player controlled tank doesnt drive in a wall
	for (auto & wall : game_data1.walls) {
		game_data1.my_tank.interact(wall);
	}
	//let the bullets move
	for (auto& bullet : game_data1.bullets) {
		bullet->update();
	}
	
	//let the bullets interact
	for (auto& bullet : game_data1.bullets) {
		//make sure the bullets bounce against walls or die
		for (auto& wall : game_data1.walls) {
			bullet->interact(wall);
		}
		//interact with the player's tank
		game_data1.my_tank.interact(bullet);

		//interact with other bullets
		for (auto& bullet2 : game_data1.bullets) {
			if (bullet != bullet2) {
				bullet->interact(bullet2);
			}
		}

		//if the bullet bounced enough, kill it
		if (bullet->death_flag) {
			game_data1.bullets.erase(std::remove(std::begin(game_data1.bullets), std::end(game_data1.bullets), bullet),
				std::end(game_data1.bullets));
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
	game_data1.walls.push_back(new wall{ sf::Vector2f{ 300,300 } });
	game_data1.walls.push_back(new wall{ sf::Vector2f{ 100,300 } });
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	while (window.isOpen()) {
		window.display();
		sf::sleep(sf::milliseconds(20));

		window.clear();
		update(window, game_data1);
		render(window, game_data1);
		//if the player's tank got hit
		if (game_data1.my_tank.death_flag) {
			window.close();
			break;
		}

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}