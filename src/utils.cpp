#include "utils.hpp"


float getVectorLength(sf::Vector2f* vector_p){
    return sqrt(pow(vector_p->x, 2) + pow(vector_p->y, 2));
}

float getVectorLength(sf::Vector2f vector_p){
    return sqrt(pow(vector_p.x, 2) + pow(vector_p.y, 2));
}

float getCosineBetweenVectors(sf::Vector2f* v1, sf::Vector2f* v2){
    return (v1->x*v2->x + v1->y*v2->y)/(getVectorLength(v1)*getVectorLength(v2));
}

float dotProduct(sf::Vector2f* v1, sf::Vector2f* v2){
    return v1->x*v2->x+v1->y*v2->y;
}


