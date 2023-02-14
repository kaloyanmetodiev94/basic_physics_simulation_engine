#include "SpringGameObject.hpp"

SpringGameObject::SpringGameObject(CircleGameObject *circle1, CircleGameObject *circle2)
    : m_circle1(circle1), m_circle2(circle2)
{
    m_spring = sf::VertexArray(sf::Lines, 2);
    m_spring[0].position = *m_circle1->getPosition();
    m_spring[1].position = *m_circle2->getPosition();
    m_spring[0].color = sf::Color::White;
    m_spring[1].color = sf::Color::White;
}

void SpringGameObject::draw(sf::RenderWindow &window) 
{
    window.draw(m_spring);
}

void SpringGameObject::update()
{
    m_spring[0].position = *this->m_circle1->getPosition();
    m_spring[1].position = *this->m_circle2->getPosition();
}
