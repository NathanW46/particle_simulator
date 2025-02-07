#ifndef RENDERER_H
#define RENDERER_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"
#include <cmath>

class Renderer {

private:
    sf::RenderWindow& window;

public:
    Renderer(sf::RenderWindow& window);
    void draw(const std::vector<Particles>& particles);
};


#endif
