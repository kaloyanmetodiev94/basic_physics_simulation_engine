#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(1024, 768), "Physics Simulation"), running(true) {}
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
    for (auto gameObject : gameObjects) {
        gameObject->update();
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
