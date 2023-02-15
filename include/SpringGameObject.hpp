#ifndef SPRING_GAME_OBJECT_HPP
#define SPRING_GAME_OBJECT_HPP

#include "GameObject.hpp"
#include "CircleGameObject.hpp"
//#include <SFML/Graphics.hpp>

class SpringGameObject : public GameObject
{
public:
    SpringGameObject(CircleGameObject *circle1, CircleGameObject *circle2, float springConstant, float restLength);
    virtual void draw(sf::RenderWindow &window) ;
    virtual void update();
    float springConstant;
    float restLength;

private:
    CircleGameObject *m_circle1, *m_circle2;
    sf::VertexArray m_spring;

};

#endif