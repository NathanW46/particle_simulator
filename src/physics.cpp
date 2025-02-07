#include "physics.h"
#include "config.h"
#include <cmath>

void Physics::applyGravity(std::vector<Particle>& particles) {
    if (particles.empty()) return;
    size_t n = particles.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            
            sf::Vector2f diff = particles[j].get_pos() - particles[i].get_pos();
            float r = std::sqrt(diff.x*diff.x + diff.y*diff.y + Config::G_SOFTENING);
            sf::Vector2f dir = diff/r;
           
            if (r == 0) continue;
            

            // apply gravitational force to all particles
            
            float force = Config::GRAVITATIONAL_CONST * particles[i].get_mass() * particles[j].get_mass() / (r*r);
            sf::Vector2f a_i = dir*(force / particles[i].get_mass());
            sf::Vector2f a_j = -dir*(force / particles[j].get_mass());

            particles[i].add_a(a_i.x, a_i.y);
            particles[j].add_a(a_j.x, a_j.y);
        }
    }

}
