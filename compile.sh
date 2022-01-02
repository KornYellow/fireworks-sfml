#!/bin/bash
echo "Compling..."
g++ fireworks.cpp -o fireworks -lsfml-graphics -lsfml-window -lsfml-system -Wall -Wextra -pedantic
echo "Completed."