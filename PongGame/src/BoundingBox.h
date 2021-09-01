#pragma once
#include "SFML/System.hpp"

struct BoundingBox {
	sf::Vector2f lowerBound;
	sf::Vector2f upperBound;
};