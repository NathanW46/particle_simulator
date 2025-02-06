#include <vector>
#include <chrono>
#include "Particle.h"
#include <SFML/Graphics.hpp>


// window dimensions
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;

// 60 FPS
const float TIME_STEP = 1.0f/ 60.0f;



int main() {

    //particle creation
    std::vector<Particle> particles;
    
    for (int i = 0; i<100; i++) {
        float x = std::rand() % WINDOW_WIDTH;
        float y = std::rand() % WINDOW_HEIGHT;
        float vx = (std::rand() % 200 - 100);
        float vy = (std::rand() % 200 - 100);
        float ax = 0;
        float ay = 1000; 
        particles.emplace_back(x, y, vx, vy, ax, ay);
    }

    //window creation 
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Particle Simulator");

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
        while (accumulatedTime >= TIME_STEP) {
            for (Particle &p : particles)
                p.update(TIME_STEP);
            accumulatedTime -= TIME_STEP;
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
