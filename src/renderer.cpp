#include "config.h"
#include "renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window(window){}


void Renderer::draw(const std::vector<Particle>& particles) {

    for (const Particle &p : particles) {
        sf::CircleShape shape(std::round(std::sqrt(p.get_mass())));
        shape.setPosition(p.get_pos().x, p.get_pos().y);
        shape.setFillColor(p.get_color());
        window.draw(shape);
    }
}
