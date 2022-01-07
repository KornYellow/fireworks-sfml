#pragma once

#include "header.hpp"
#include "utility.hpp"
#include "firework.hpp"

class FireworkManager {
public:
	FireworkManager(sf::RenderWindow *window) {

		this->window = window;
	}

	void update(uint64_t delta_time) {

		for(size_t n = 0; n < this->fireworks.size(); n++) {

			this->fireworks[n].update(delta_time);

			if(!this->fireworks[n].get_is_child()) {
				if(this->fireworks[n].get_y_speed() >= 0) {

					this->create_explode(this->fireworks[n]);
					this->fireworks.erase(this->fireworks.begin() + n);
					continue;
				}
			}
			else {
				if(this->fireworks[n].get_y() >= WINDOW_HEIGHT + (this->fireworks[n].get_radius() * 16) ||
				   this->fireworks[n].get_alpha() <= 0) {

					this->fireworks.erase(this->fireworks.begin() + n);
					continue;
				}
			}
		}
	}
	void draw() {

		for(size_t n = 0; n < this->fireworks.size(); n++)
			this->fireworks[n].draw();
	}

	void create_firework(float x) {

		Firework firework(this->window);

		float radius = float(random_int_range(FIREWORK_MIN_RADIUS, FIREWORK_MAX_RADIUS)) / 10.f;
		firework.set_radius(radius);

		firework.set_x(x);
		firework.set_y(WINDOW_HEIGHT + (radius * 2));

		float x_speed = float(random_int_range(-FIREWORK_SHIFT_RATE, FIREWORK_SHIFT_RATE)) / 10.f;
		float y_speed = -15 * (10 - radius);
		firework.set_x_speed(x_speed);
		firework.set_y_speed(y_speed);

		firework.set_x_acce(0);
		firework.set_y_acce(FIREWORK_GRAVITY);

		this->fireworks.push_back(firework);
	}
	void create_explode(Firework root) {

		uint8_t detail = 5;
		for(uint8_t n = 0; n < 360 / detail; n++) {

			uint angle = n * detail;

			Firework child(this->window);

			float radius = float(random_int_range(CHILD_MIN_RADIUS, CHILD_MAX_RADIUS)) / 10.f;
			child.set_radius(radius);

			child.set_x(root.get_x());
			child.set_y(root.get_y());

			child.set_x_speed(0);
			child.set_y_speed(0);

			child.set_x_burst((random_int_range(30, 50) * cos(angle)) * (root.get_radius() / 3));
			child.set_y_burst((random_int_range(30, 50) * sin(angle)) * (root.get_radius() / 3));

			child.set_x_acce(0);
			child.set_y_acce(FIREWORK_GRAVITY);

			child.set_is_child(true);
			this->fireworks.push_back(child);
		}
	}
private:
	sf::RenderWindow *window;
	std::vector <Firework> fireworks;
};