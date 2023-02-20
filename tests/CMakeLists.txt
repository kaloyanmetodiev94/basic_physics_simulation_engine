cmake_minimum_required(VERSION 3.0)

project(GameEngineTests)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)


#Remove the main.cpp from the SOURCES variable
list(FILTER SOURCES EXCLUDE REGEX main.cpp)

# Test executables
add_executable(circle_game_object_test circle_game_object_test.cpp ${SOURCES})
target_include_directories(circle_game_object_test PUBLIC ${INCLUDES})
target_link_libraries(circle_game_object_test PRIVATE Catch2::Catch2WithMain sfml-graphics)


# Register tests with CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(circle_game_object_test)
