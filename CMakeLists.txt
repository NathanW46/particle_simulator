cmake_minimum_required(VERSION 3.12)
project(particle_simulation)


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES
    src/main.cpp
    src/simulation.cpp
    src/particle.cpp
    src/physics.cpp
    src/renderer.cpp
)

include_directories(include)

add_executable(particle_sim ${SOURCES})


#libraries 
#find_package(SFML 2.5 COMPONENTS graphic window system REQUIRED)
#target_link_libraries(particle_simulator sfml-graphics sfml-window sfml-system)
