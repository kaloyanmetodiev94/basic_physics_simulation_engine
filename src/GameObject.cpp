#include "GameObject.hpp"
#include "iostream"

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
  std::cout << "Velocity set to: " << this->velocity.x << ", " << this->velocity.y << std::endl;
}