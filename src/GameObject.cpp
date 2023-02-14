#include "GameObject.hpp"


GameObject::GameObject() {
  texture.loadFromFile("../assets/background.jpeg");
  sprite.setTexture(texture);
}

GameObject::~GameObject() {}

void GameObject::update() {}

void GameObject::draw(sf::RenderWindow& window) {
  window.draw(sprite);
}

void GameObject::setVelocity(const sf::Vector2f& velocity) {
  this->velocity=velocity;
  std::cout << "Velocity set to: " << this->velocity.x << ", " << this->velocity.y <<" Total:"<<getVectorLength(velocity)<<std::endl;
}

sf::Vector2f* GameObject::getPosition(){
  return &this->position;
}

sf::Vector2f* GameObject::getVelocity(){
  return &this->velocity;
}

//general vector operation functions

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

sf::Vector2f operatorFunction( sf::Vector2f* v1,  sf::Vector2f* v2, char op) {
    sf::Vector2f result;

    switch (op) {
        case '+':
            result = sf::Vector2f(v1->x+v2->x, v1->y+v2->y);
            break;
        case '-':
            result = sf::Vector2f(v2->x-v1->x, v2->y-v1->y);
            break;
        default:
            result = sf::Vector2f(0.f, 0.f);
    }

    return result;
}