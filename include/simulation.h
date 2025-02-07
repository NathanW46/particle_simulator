#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

class Simulator {

private:
    sf::RenderWindow window;
    Renderer renderer;
    std::vector<Particle> particles;

    void Events();
    void update(float dt);
    void render();

public:
    Simulator(int numParticles);
    void run();

};


#endif
