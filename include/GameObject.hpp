#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


#define SCREEN_X 1024
#define SCREEN_Y 768
#include <SFML/Graphics.hpp>
#include <cmath>
#include "iostream"

class GameObject {
public:
  GameObject(); //i will use this as image background for now
  GameObject(const sf::Vector2f& position) : position(position) {}
  virtual ~GameObject();

  virtual void update();
  virtual void draw(sf::RenderWindow& window);
  virtual void setVelocity(const sf::Vector2f& position);
  virtual sf::Vector2f* getPosition();
  virtual sf::Vector2f* getVelocity();
  sf::Vector2f position;
  sf::Vector2f velocity;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};
float getVectorLength(sf::Vector2f* vector_p); //this is not the best position, but I need a length function
float getVectorLength(sf::Vector2f vector_p); //overload it, to use it in the initializations as well
float getCosineBetweenVectors(sf::Vector2f* vector_p1, sf::Vector2f* vector_p2);
float dotProduct(sf::Vector2f* v1, sf::Vector2f* v2);

#endif
