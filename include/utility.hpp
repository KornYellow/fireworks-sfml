#pragma once

#include "header.hpp"

int random_int(int a) {

	return rand() % (a + 1);
}

int random_int_range(int a, int b) {

	return rand() % (b + 1 - a) + a;
}