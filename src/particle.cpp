#include <iostream>
#include <cmath>
#include "Particle.h"
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

void Particle::add_a(sf::Vector2f a) {
    ax += a.x;
    ay += a.y;
}


std::pair<float, float> Particle::get_pos() const {
    return {x, y};
}

float Particle::get_mass() const {
    return m;
}
