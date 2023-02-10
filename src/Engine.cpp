#include "Engine.hpp"

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
                    handleCollision(circle1,circle2);
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

void Engine::handleCollision(CircleGameObject* circle1, CircleGameObject* circle2) {
    sf::Vector2f* position1 = circle1->getPosition();
    sf::Vector2f* position2 = circle2->getPosition();
    sf::Vector2f* velocity1 = circle1->getVelocity();
    sf::Vector2f* velocity2 = circle2->getVelocity();

    float radius1 = circle1->getRadius();
    float radius2 = circle2->getRadius();

    // Get angle between the two centres of circles relative to the whole frame
    float angle = atan2(position2->y - position1->y, position2->x - position1->x); //atan2 should always give <Pi radians

    float distance = sqrt(pow(position2->x - position1->x, 2) + pow(position2->y - position1->y, 2));
    float u1 = getVectorLength(velocity1);
    float u2 = getVectorLength(velocity2);
    
    //Calculating the component of the velocity that is directed towards the centers of the two circles.
    //These need to be reflected and added to the other vectors
    sf::Vector2f velocityDifference1((position2->x - position1->x)*u1/distance,(position2->y - position1->y)*u1/distance);
    sf::Vector2f velocityDifference2(-(position2->x - position1->x)*u2/distance,-(position2->y - position1->y)*u2/distance); 


    //Calculate the new velocity as new_velocity_vector=old_velocity_vector - 2*reflect_component
    sf::Vector2f newVelocity1(velocity1->x-2*velocityDifference1.x,velocity1->y-2*velocityDifference1.y);
    sf::Vector2f newVelocity2(velocity2->x-2*velocityDifference2.x,velocity2->y-2*velocityDifference2.y);

    // Update the velocity of the two circles
    circle1->setVelocity(newVelocity1);
    circle2->setVelocity(newVelocity2);
}

