#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include "GameObject.hpp"
#include "CircleGameObject.hpp"
#include "SpringGameObject.hpp"
#include <SFML/Graphics.hpp>



#define _USE_MATH_DEFINES

class Engine {
public:
  Engine();
  ~Engine();

  void run();
  void handleEvents();
  void update();
  void render();
  void addGameObject(GameObject* gameObject);
  bool isRunning() const; //we shouldn't be able to kill alter the engine state from inside isRunning() in code --> make it const

  void handleCollision(CircleGameObject* ,CircleGameObject*, float distance);
  void draw(sf::RenderWindow& window);

private:
    sf::RenderWindow window;
    std::vector<GameObject*> gameObjects;
    bool running;
};

#endif