#include "CircleGameObject.hpp"
#include "iostream"

CircleGameObject::CircleGameObject(const sf::Vector2f& position, float radius, const sf::Color& color)
    : GameObject(position), radius(radius), color(color) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(position);
    shape.setFillColor(color);
    std::cout << "Circle initial position: " << position.x << ", " << position.y << std::endl;
}

void CircleGameObject::update() {
    shape.move(velocity);
}

void CircleGameObject::draw(sf::RenderWindow& window) {
    window.draw(shape);
}