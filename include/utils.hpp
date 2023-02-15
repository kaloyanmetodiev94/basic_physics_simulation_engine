#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/System/Vector2.hpp>
#include <cmath>

float getVectorLength(sf::Vector2f* vector_p); //this is not the best position, but I need a length function
float getVectorLength(sf::Vector2f vector_p); //overload it, to use it in the initializations as well
float getCosineBetweenVectors(sf::Vector2f* vector_p1, sf::Vector2f* vector_p2);
float dotProduct(sf::Vector2f* v1, sf::Vector2f* v2);

#endif // UTILS_HPP