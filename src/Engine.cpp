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
                    handleCollision(circle1,circle2,distance);
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

void Engine::handleCollision(CircleGameObject* circle1, CircleGameObject* circle2, float distance) {
    sf::Vector2f* position1 = circle1->getPosition();
    sf::Vector2f* position2 = circle2->getPosition();
    sf::Vector2f* velocity1 = circle1->getVelocity();
    sf::Vector2f* velocity2 = circle2->getVelocity();

    // Get the unit vector along the line between the centres where the circles hit
    sf::Vector2f distance_unit_vector((position2->x - position1->x)/distance,(position2->y - position1->y)/distance);
    
    // Get the dot products. i.e. the length of the vector along that unit vector for each velocity
    float u1_diff = dotProduct(&distance_unit_vector,velocity1);
    float u2_diff = dotProduct(&distance_unit_vector,velocity2);

    // Calculate the difference one needs to make to the vector in order to reflect it along the distance_unit_vector
    sf::Vector2f velocityDifference1 = distance_unit_vector*u1_diff*2.0f;
    sf::Vector2f velocityDifference2 = distance_unit_vector*u2_diff*2.0f;

    // Subtract the difference v_new = v_old - (v_old . n)n
    sf::Vector2f newVelocity1 = *velocity1 - velocityDifference1;
    sf::Vector2f newVelocity2 = *velocity2 - velocityDifference2;
    //sf::Vector2f newVelocity1 = operatorFunction(&velocityDifference1,velocity1,'-');
    //sf::Vector2f newVelocity2 = operatorFunction(&velocityDifference2,velocity2,'-');

    // Update the velocity of the two circles
    circle1->setVelocity(newVelocity1);
    circle2->setVelocity(newVelocity2);
}

