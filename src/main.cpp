#include <SFML/Graphics.hpp>
#include "Engine.hpp"

int main() {
  Engine engine;

  GameObject background_img;
  engine.addGameObject(&background_img);

  CircleGameObject circle(sf::Vector2f(700, 100), 10.0f, sf::Color::Green);
  circle.setVelocity(sf::Vector2f(-0.01, 0.01));
  engine.addGameObject(&circle);

  engine.run();

  return 0;
}