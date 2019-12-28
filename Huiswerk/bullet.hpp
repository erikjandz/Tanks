#pragma once
#include "drawable.hpp"

class bullet : public drawable {
public:
	bullet(sf::Vector2f position):
		drawable{ position }
	{
		image.loadFromFile("bullet.png");
		image.createMaskFromColor(sf::Color::White, 0);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.1, 0.1));
		sprite.setOrigin(sf::Vector2f{ 100, 100 });
		sprite.setPosition(position);
		speed = sf::Vector2f{ 1,1 };
	}


	void draw(sf::RenderWindow & window)override{
		window.draw(sprite);
	}

	void update()override {
		position += speed;
		sprite.setPosition(position);
	}

	sf::Vector2f speed;
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
};