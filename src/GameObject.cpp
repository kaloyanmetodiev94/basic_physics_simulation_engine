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

void GameObject::setVelocity(const sf::Vector2f& velocity, bool verbose) {
  this->velocity=velocity;
  if(verbose){
    std::cout << "Velocity set to: " << this->velocity.x << ", " << this->velocity.y <<" Total:"<<getVectorLength(velocity)<<std::endl;
  }
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
