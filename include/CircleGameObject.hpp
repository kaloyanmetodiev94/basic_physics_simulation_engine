#ifndef CIRCLE_GAME_OBJECT_HPP
#define CIRCLE_GAME_OBJECT_HPP

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

class CircleGameObject : public GameObject {
public:
    CircleGameObject(const sf::Vector2f& position, float radius, const sf::Color& color);
    virtual void update();
    virtual void draw(sf::RenderWindow& window);

private:
    float radius;
    sf::Color color;
    sf::CircleShape shape;
};

#endif