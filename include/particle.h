#ifndef PARTICLE_H
#define PARTICLE_H

#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Particle {
    private:
	float x, y;
	float vx, vy;
	float ax, ay;
	float m;
	sf::Color c;
    
    public:
	
	Particle(float x, float y, float vx, float vy, float ax, float ay, float m, sf::Color c);

	void update(float dt);

	void print_pos() const;
	
	void add_a(float a_x, float a_y);

	//getters
	sf::Vector2f get_pos() const;
	float get_mass() const;
	sf::Color get_color() const;
};

#endif

