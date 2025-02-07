#ifndef PHYSICS_H
#define PHYSICS_H

#include "particle.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Physics {
    
public:
    static void applyGravity(std::vector<Particle>& p);

};

#endif
