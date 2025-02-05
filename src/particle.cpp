#include <iostream>
#include <cmath>
#include "particle.h"


particle::particle(float x, float y, float vx, float vy, float ax, float ay) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
}

void particle::update(float dt) {
    x = x + vx*dt + 0.5*ax*pow(2, dt);
    y = y + vy*dt + 0.5*ay*pow(2, dt);
}

void particle::print_pos() const{
    std::cout << "Current Position (x,y) = (" << x << ", " << y << ")\n";
}
