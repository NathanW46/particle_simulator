#include <iostream>
#include <cmath>
#include "Particle.h"


Particle::Particle(float x, float y, float vx, float vy, float ax, float ay) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
}

void Particle::update(float dt) {
    vx += ax*dt;
    vy += ay*dt;
    
    x += vx*dt; 
    y += vy*dt;
}

void Particle::print_pos() const{
    std::cout << "Current Position (x,y) = (" << x << ", " << y << ")\n";
}

std::pair<float, float> Particle::get_pos() const {
    return {x, y};
}
