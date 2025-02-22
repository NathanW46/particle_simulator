#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
//#include "particle.h"

class Renderer {
	private:
		sf::RenderWindow& window;
	
	public:
		Renderer(sf::RenderWindow& window);
		/*void draw(const std::vector<Particle>& particles);*/
};

#endif



