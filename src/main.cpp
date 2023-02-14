#include <SFML/Graphics.hpp>
#include "Engine.hpp"

int main() {
  Engine engine;

  GameObject background_img;
  engine.addGameObject(&background_img);

  CircleGameObject circle(sf::Vector2f(702, 104), 15.0f, sf::Color::Green);
  circle.setVelocity(sf::Vector2f(-0.18, 0.18));

  CircleGameObject circle1(sf::Vector2f(98, 690), 15.0f, sf::Color::Blue);
  circle1.setVelocity(sf::Vector2f(+0.10, -0.10));

  SpringGameObject spring(&circle,&circle1);

  engine.addGameObject(&circle);
  engine.addGameObject(&circle1);
  engine.addGameObject(&spring);
  engine.run();

  return 0;
}