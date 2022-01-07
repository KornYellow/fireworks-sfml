#pragma once

#include "header.hpp"

class Firework {
public:
	Firework(sf::RenderWindow *window) {

		this->window = window;

		this->x = -100;
		this->y = -100;
		this->x_speed = 0;
		this->y_speed = 0;
		this->x_acce = 0;
		this->y_acce = 0;
		this->x_burst = 0;
		this->y_burst = 0;
		this->alpha = 255;
		this->is_child = false;

		this->shape.setPosition(this->x, this->y);
		this->shape.setFillColor(sf::Color::White);
	}

	void update(uint64_t delta_time) {

		this->x_speed += this->x_acce * DELTA_TIME;
		this->y_speed += this->y_acce * DELTA_TIME;
		if(this->y_speed > 20) this->y_speed = 20;

		this->x += (this->x_speed + this->x_burst) * DELTA_TIME;
		this->y += (this->y_speed + this->y_burst) * DELTA_TIME;

		if(this->is_child) {

			this->x_burst *= 0.94;
			this->y_burst *= 0.94;

			if(this->alpha > 0) this->alpha -= 30 * DELTA_TIME;
			if(this->alpha < 0) this->alpha = 0;
		}

		this->shape.setPosition(this->x, this->y);
		this->shape.setFillColor(sf::Color(255, 255, 255, this->alpha));
	}
	void draw() {

		this->window->draw(this->shape);
	}

	void set_x(float x) { this->x = x; }
	float get_x() { return this->x; }
	void set_y(float y) { this->y = y; }
	float get_y() { return this->y; }
	void set_x_speed(float x_speed) { this->x_speed = x_speed; }
	float get_x_speed() { return this->x_speed; }
	void set_y_speed(float y_speed) { this->y_speed = y_speed; }
	float get_y_speed() { return this->y_speed; }
	void set_x_acce(float x_acce) { this->x_acce = x_acce; }
	float get_x_acce() { return this->x_acce; }
	void set_y_acce(float y_acce) { this->y_acce = y_acce; }
	float get_y_acce() { return this->y_acce; }
	void set_x_burst(float x_burst) { this->x_burst = x_burst; }
	float get_x_burst() { return this->x_burst; }
	void set_y_burst(float y_burst) { this->y_burst = y_burst; }
	float get_y_burst() { return this->y_burst; }
	void set_radius(float radius) { this->shape.setRadius(radius); }
	float get_radius() { return this->shape.getRadius(); }
	void set_alpha(float alpha) { this->alpha = alpha; }
	float get_alpha() { return this->alpha; }
	void set_is_child(bool is_child) { this->is_child = is_child; }
	bool get_is_child() { return this->is_child; }
private:
	sf::RenderWindow *window;
	sf::CircleShape shape;

	float x;
	float y;
	float x_speed;
	float y_speed;
	float x_acce;
	float y_acce;
	float x_burst;
	float y_burst;
	float alpha;
	bool is_child;
};