#include <SFML/Graphics.hpp>
#include "Engine.hpp"

int main() {
  Engine engine;

  GameObject background_img;
  engine.addGameObject(&background_img);

  CircleGameObject circle(sf::Vector2f(700, 100), 10.0f, sf::Color::Green);
  circle.setVelocity(sf::Vector2f(-0.05, 0.05));

  CircleGameObject circle1(sf::Vector2f(100, 700), 10.0f, sf::Color::Green);
  circle1.setVelocity(sf::Vector2f(+0.03, -0.03));

  engine.addGameObject(&circle);
  engine.addGameObject(&circle1);
  engine.run();

  return 0;
}