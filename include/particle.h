#ifndef PARTICLE_H
#define PARTICLE_H


#include <iostream>



class particle {
    private:
	float x, y;
	float vx, vy;
	float ax, ay;

    public:
	
	particle(float x, float y, float vx, float vy, float ax, float ay);

	void update(float dt);

	void print_pos() const;

};

#endif

