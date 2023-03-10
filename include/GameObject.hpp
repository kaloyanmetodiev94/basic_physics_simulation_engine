#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


#define SCREEN_X 1024
#define SCREEN_Y 768
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "iostream"

class GameObject {
public:
  GameObject(); //i will use this as image background for now
  GameObject(const sf::Vector2f& position) : position(position) {}
  virtual ~GameObject();

  virtual void update();
  virtual void draw(sf::RenderWindow& window);
  virtual void setVelocity(const sf::Vector2f& position,bool verbose = true);
  virtual sf::Vector2f* getPosition();
  virtual sf::Vector2f* getVelocity();
  sf::Vector2f position;
  sf::Vector2f velocity;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};


#endif
