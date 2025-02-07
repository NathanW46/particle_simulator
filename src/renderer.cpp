#include "config.h"
#include "renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window(window){}


void Renderer::draw(const std::vector<Particle>& particles) {

    for (const Particle &p : particles) {
        sf::CircleShape shape(std::round(std::sqrt(p.get_mass()/3.14)));
        shape.setPosition(p.get_pos().first, p.get_pos().second);
        shape.setFillColor(p.get_color());
        window.draw(shape);
    }
}
