#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "CircleGameObject.hpp"

TEST_CASE("CircleGameObject - position update", "[CircleGameObject]")
{
    
    CircleGameObject circle(sf::Vector2f(50, 50), 2.f, sf::Color::Green);
    circle.setVelocity(sf::Vector2f(1,0));

    circle.update();
    REQUIRE(circle.getPosition()->x == 51.f);
    REQUIRE(circle.getPosition()->y == 50.f);

    circle.update();
    REQUIRE(circle.getPosition()->x == 52.f);
    REQUIRE(circle.getPosition()->y == 50.f);
}


TEST_CASE("CircleGameObject - apply force", "[CircleGameObject]")
{
    CircleGameObject circle(sf::Vector2f(0, 0), 2.f, sf::Color::Green);
    circle.applyForce(sf::Vector2f(1, 0));
    REQUIRE(circle.getVelocity()->x == 0.25);
    REQUIRE(circle.getVelocity()->y == 0.f);

    circle.applyForce(sf::Vector2f(0, -1));
    REQUIRE(circle.getVelocity()->x == 0.25);
    REQUIRE(circle.getVelocity()->y == -0.25);
}