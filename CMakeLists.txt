cmake_minimum_required(VERSION 3.0)

project(PhysicsSimulation VERSION 1.0.0 DESCRIPTION "Simulation engine for real physics")
set(CMAKE_CXX_STANDARD 17)
Include(FetchContent)

# Configure SFML library with FetchContent
set(SFML_VERSION "2.5.1")
FetchContent_Declare(
  SFML
  URL "https://github.com/SFML/SFML/archive/${SFML_VERSION}.zip"
)
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(SFML)


set(INCLUDES
    ${PhysicsSimulation_SOURCE_DIR}/include
)
file(GLOB SOURCES src/*.cpp)

#Build the main executable
add_executable(PhysicsSimulation ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
target_link_libraries(${PROJECT_NAME} sfml-graphics)
# Share SOURCES variable with tests
set_property(TARGET ${PROJECT_NAME} PROPERTY SOURCES ${SOURCES})

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
  add_subdirectory(tests)
  enable_testing()
endif()

