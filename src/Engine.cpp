#include "Engine.hpp"
#include "iostream"
#include <cmath>

Engine::Engine() : window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Physics Simulation"), running(true) {}
Engine::~Engine() {} ;

void Engine::run() {
    while (isRunning()) {
        handleEvents();
        update();
        render();
    }
}


void Engine::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            running = false;
        }
    }
}

void Engine::update() {
    //update each game object
    for (auto gameObject : gameObjects) { 
        gameObject->update();
    }
    //handle collision
    for (int i = 0; i < gameObjects.size(); i++) { 
        for (int j = i + 1; j < gameObjects.size(); j++) {
            CircleGameObject* circle1 = dynamic_cast<CircleGameObject*>(gameObjects[i]); //to test out downcasting
            CircleGameObject* circle2 = dynamic_cast<CircleGameObject*>(gameObjects[j]);
            if (circle1 && circle2) { //other game objects should not be circles and this should return NULL pointer
                sf::Vector2f* position1 = circle1->getPosition();
                sf::Vector2f* position2 = circle2->getPosition();
                float distance = sqrt(pow(position2->x - position1->x, 2) + pow(position2->y - position1->y, 2));
                float radius1 = circle1->getRadius();
                float radius2 = circle2->getRadius();
                if (distance <= radius1 + radius2) {
                    std::cout << "collision" <<std::endl;
                }
            }
        }
    }
}

void Engine::render() {
    window.clear();
    for (auto gameObject : gameObjects) {
        gameObject->draw(window);
    }
    window.display();
}

void Engine::addGameObject(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

bool Engine::isRunning() const {
    return running;
}

void Engine::draw(sf::RenderWindow& window) {
  for (GameObject* gameObject : gameObjects) {
    gameObject->draw(window);
  }
}
