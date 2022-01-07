#pragma once

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 800
#define PROGRAM_NAME "Fireworks SFML"

#define FIREWORK_MIN_RADIUS 30
#define FIREWORK_MAX_RADIUS 55
#define FIREWORK_MIN_HEIGHT 80
#define FIREWORK_MAX_HEIGHT 110
#define FIREWORK_SHIFT_RATE 30
#define FIREWORK_GRAVITY 7

#define CHILD_MIN_RADIUS 20
#define CHILD_MAX_RADIUS 30

#define DELTA_TIME float(delta_time / 100000.f)

#include <iostream>
#include <string>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>