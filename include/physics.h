#ifndef PHYSICS_H
#define PHYSICS_H

#include "Particle.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Physics {
    
public:
    static void applyGravity(Particle& p);

};

#endif
