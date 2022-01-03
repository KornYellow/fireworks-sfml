#pragma once

#include "header.hpp"
#include "firework_manager.hpp"

class Application {
public:
	Application() {

		this->window = new sf::RenderWindow(sf::VideoMode(1400, 800), "Fireworks SFML");
		this->firework_manager = new FireworkManager(this->window);
	}
	~Application() {

		delete this->window;
		delete this->firework_manager;
	}
	void run() {

		while(this->window->isOpen()) {

			this->eventHandler();

			this->firework_manager->update();

			this->window->clear();
			this->firework_manager->draw();
			this->window->display();
		}
	}
private:
	void eventHandler() {

		sf::Event event;
		while(this->window->pollEvent(event)) {

			switch(event.type) {

				case sf::Event::Closed:
					this->window->close();
					break;

				default:
					break;
			}
		}
	}

	sf::RenderWindow *window;
	FireworkManager *firework_manager;
};