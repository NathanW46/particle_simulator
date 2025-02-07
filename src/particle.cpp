#include <iostream>
#include <cmath>
#include "particle.h"
#include <SFML/Graphics.hpp>


Particle::Particle(float x, float y, float vx, float vy, float ax, float ay, float m, sf::Color c) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
    this->m = m;
    this->c = c;
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

void Particle::add_a(float a_x, float a_y) {
    ax += a_x;
    ay += a_y;
}


sf::Vector2f Particle::get_pos() const {
    return {x, y};
}

float Particle::get_mass() const {
    return m;
}

sf::Color Particle::get_color() const {
    return c;
}
