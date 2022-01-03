#pragma once

#include "firework.hpp"

class FireworkManager {
public:
	FireworkManager(sf::RenderWindow *window) {

		this->window = window;
	}

	void update() {
	}
	void draw() {
	}
private:
	sf::RenderWindow *window;

	std::vector <Firework*> fireworks;
};