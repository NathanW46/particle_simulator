cmake_minimum_required(VERSION 3.10)
project(Particle_Simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(Particle_Simulator ${SOURCES})

# SFML 3.0
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

target_include_directories(Particle_Simulator PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Particle_Simulator PRIVATE SFML::Graphics SFML::Window SFML::System)



