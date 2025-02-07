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
	
	void add_a(sf::Vector2f a);

	//getters
	std::pair<float, float> get_pos() const;
	float get_mas() const;
};

#endif

