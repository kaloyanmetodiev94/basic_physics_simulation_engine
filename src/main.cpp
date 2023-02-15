#include <SFML/Graphics.hpp>
#include "Engine.hpp"

int main() {
  Engine engine;

  GameObject background_img;
  engine.addGameObject(&background_img);

  CircleGameObject circle(sf::Vector2f(702, 104), 15.0f, sf::Color::Green);
  circle.setVelocity(sf::Vector2f(-0.08, 0.08));

  CircleGameObject circle1(sf::Vector2f(98, 690), 15.0f, sf::Color::Blue);
  circle1.setVelocity(sf::Vector2f(+0.04, -0.04));

  SpringGameObject spring(&circle,&circle1,0.00002, 600);

  engine.addGameObject(&circle);
  engine.addGameObject(&circle1);
  engine.addGameObject(&spring);
  engine.run();

  return 0;
}