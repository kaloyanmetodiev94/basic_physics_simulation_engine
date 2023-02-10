cmake_minimum_required(VERSION 3.0)

project(PhysicsSimulation VERSION 1.0.0 DESCRIPTION "Simulation engine for real physics")

set(CMAKE_CXX_STANDARD 17)

message("--If SFML search fails, try running: sudo apt-get install libsfml-dev ")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)


include_directories(${PhysicsSimulation_SOURCE_DIR}/include)

file(GLOB SOURCES src/*.cpp)
add_executable(PhysicsSimulation ${SOURCES})

target_link_libraries(PhysicsSimulation sfml-graphics)