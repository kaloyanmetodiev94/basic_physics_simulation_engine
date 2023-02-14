#ifndef SPRING_GAME_OBJECT_HPP
#define SPRING_GAME_OBJECT_HPP

#include "GameObject.hpp"
#include "CircleGameObject.hpp"
//#include <SFML/Graphics.hpp>

class SpringGameObject : public GameObject
{
public:
    SpringGameObject(CircleGameObject *circle1, CircleGameObject *circle2);
    virtual void draw(sf::RenderWindow &window) ;
    virtual void update();

private:
    CircleGameObject *m_circle1, *m_circle2;
    sf::VertexArray m_spring;
};

#endif