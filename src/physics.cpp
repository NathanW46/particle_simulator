#include "physics.h"
#include "config.h"
#include <cmath>

void Physics::applyGravity(std::vector<Particle>& p) {
    if (particles.empty()) return;
    size_t n = particles.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            
            sf::Vector2f diff = p[j].get_pos() - p[i].get_pos();
            float r = std::sqrt(diff.x*diff.x + diff.y*diff.y + Config::G_SOFTENING);
            sf::Vector2f dir = diff/r;
           
            if (r == 0) continue;

            //elastic collisions
            float min_dist = std::sqrt(p[i].get_mass()) + std::sqrt(p[j].get_mass());
            if (r < min_dist + config::MIN_PDIST_BUFF) {
                Physics::bounce(p[i], p[j], dir);
            }
            // apply gravitational force to all particles
            
            float force = Config::GRAVITATIONAL_CONST * p[i].get_mass() * p[j].get_mass() / (r*r);
            sf::Vector2f a_i = dir*(force / p[i].get_mass());
            sf::Vector2f a_j = -dir*(force / p[j].get_mass());

            p[i].add_a(a_i.x, a_i.y);
            p[j].add_a(a_j.x, a_j.y);
        }
    }

}

void Physics::bounce(Particle p1, Particle p2, float dir) {
    

}
