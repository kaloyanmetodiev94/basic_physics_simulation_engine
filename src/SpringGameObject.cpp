#include "SpringGameObject.hpp"

SpringGameObject::SpringGameObject(CircleGameObject *circle1, CircleGameObject *circle2, float springConstant, float restLength)
    : m_circle1(circle1), m_circle2(circle2), springConstant(springConstant), restLength(restLength)
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

    sf::Vector2f diff = m_spring[0].position - m_spring[1].position;
    float length = getVectorLength(diff);
    sf::Vector2f norm = diff / length;
    norm *= springConstant * (length - restLength);
    sf::Vector2f norm_neg = -norm;
    m_circle1->applyForce(&norm_neg);
    m_circle2->applyForce(&norm);
}
