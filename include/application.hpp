#pragma once

#include "header.hpp"
#include "utility.hpp"
#include "firework_manager.hpp"

class Application {
public:
	Application() {

		srand(time(NULL));

		this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), PROGRAM_NAME);
		this->window->setFramerateLimit(75);

		this->firework_manager = new FireworkManager(this->window);
	}
	~Application() {

		delete this->window;
		delete this->firework_manager;
	}
	void run() {

		while(this->window->isOpen()) {

			this->eventHandler();

			uint64_t delta_time = this->clock.getElapsedTime().asMicroseconds();
			this->clock.restart();
			this->firework_manager->update(delta_time);

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

				case sf::Event::TextEntered:
					if(event.text.unicode == 'q')
						this->window->close();
					break;

				case sf::Event::MouseButtonPressed:
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

						float mouse_x = sf::Mouse::getPosition().x;
						this->firework_manager->create_firework(mouse_x);
					}
					break;

				default:
					break;
			}
		}

		if(random_int(8) == 0) {
			this->firework_manager->create_firework(random_int_range(32, WINDOW_WIDTH - 32));
		}
	}

	sf::RenderWindow *window;
	FireworkManager *firework_manager;
	sf::Clock clock;
};