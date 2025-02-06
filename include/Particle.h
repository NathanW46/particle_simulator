#ifndef PARTICLE_H
#define PARTICLE_H

#include <utility>
#include <iostream>



class Particle {
    private:
	float x, y;
	float vx, vy;
	float ax, ay;

    public:
	
	Particle(float x, float y, float vx, float vy, float ax, float ay);

	void update(float dt);

	void print_pos() const;

	std::pair<float, float> get_pos() const;
};

#endif

