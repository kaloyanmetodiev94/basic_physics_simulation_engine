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

