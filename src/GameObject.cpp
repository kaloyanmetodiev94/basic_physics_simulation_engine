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

float getVectorLength(sf::Vector2f* vector_p){
    return sqrt(pow(vector_p->x, 2) + pow(vector_p->y, 2));
}

float getVectorLength(sf::Vector2f vector_p){
    return sqrt(pow(vector_p.x, 2) + pow(vector_p.y, 2));
}