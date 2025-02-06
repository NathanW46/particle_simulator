cmake_minimum_required(VERSION 3.12)
project(Particle_Simulation)


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES
    src/main.cpp
    src/simulation.cpp
    src/Particle.cpp
    src/physics.cpp
    src/renderer.cpp
)

include_directories(include)

add_executable(particle_sim ${SOURCES})


#libraries 
#set(SFML_DIR "/usr/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(particle_sim PRIVATE sfml-graphics sfml-window sfml-system)
