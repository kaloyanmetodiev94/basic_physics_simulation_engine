#include "CircleGameObject.hpp"

CircleGameObject::CircleGameObject(const sf::Vector2f& position, float radius, const sf::Color& color)
    : GameObject(position), radius(radius), color(color) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(position);
    shape.setFillColor(color);
    std::cout << "Circle initial position: " << position.x << ", " << position.y << std::endl;
}

void CircleGameObject::update() {
    position += velocity;

    // Bounce back when hitting the edges of the screen
    if (position.x - shape.getRadius() < 0 || position.x + shape.getRadius() > SCREEN_X) {
        velocity.x = -velocity.x;
    }
    if (position.y - shape.getRadius() < 0 || position.y + shape.getRadius() > SCREEN_Y) {
        velocity.y = -velocity.y;
    }
}


void CircleGameObject::draw(sf::RenderWindow& window) {
    shape.setPosition(position);
    window.draw(shape);
}

float CircleGameObject::getRadius(){
    return radius;
}