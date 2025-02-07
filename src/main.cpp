#include <vector>
#include <chrono>
#include "Particle.h"
#include "Config.h"
#include <SFML/Graphics.hpp>






int main() {

    //particle creation
    std::vector<Particle> particles;
    
    for (int i = 0; i<100; i++) {
        float x = std::rand() % Config::WINDOW_WIDTH;
        float y = std::rand() % Config::WINDOW_HEIGHT;
        float vx = (std::rand() % 200 - 100);
        float vy = (std::rand() % 200 - 100);
        float ax = 0.0f;
        float ay = 0.0f; 
        float m = 0.0f;
        sf::Color c = sf::Color((std::rand()%256), (std::rand()%256), (std::rand()%256));
        particles.emplace_back(x, y, vx, vy, ax, ay, m, c);
    }

    //window creation 
    sf::RenderWindow window(
        sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Particle Simulator");

    // Timer for fixed frame rate
    sf::Clock clock;
    float accumulatedTime = 0.0f;


    // Game loop
    while (window.isOpen()) {
        //Poll Events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //10 fps
        float frameTime = clock.restart().asSeconds();
        accumulatedTime += frameTime;

        //update at fixed intervals
        while (accumulatedTime >= Config::TIME_STEP) {
            for (Particle &p : particles)
                p.update(Config::TIME_STEP);
            accumulatedTime -= Config::TIME_STEP;
        }
        
        //render particles
        window.clear(sf::Color::Black);
        for (const Particle &p : particles) {
            sf::CircleShape shape(5);
            shape.setPosition(p.get_pos().first, p.get_pos().second);
            shape.setFillColor(sf::Color::White);
            window.draw(shape);
        }
        window.display();   



    }
}
