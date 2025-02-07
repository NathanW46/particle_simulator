#include "simulator.h"
#include "config.h"


Simulator::Simulator(int numParticles) 
   : window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Particle Simulator"), renderer(window) { 
    
    // particle creation
     for (int i = 0; i<numParticles; ++i) {
        float x = std::rand() % Config::WINDOW_WIDTH;
        float y = std::rand() % Config::WINDOW_HEIGHT;
        float vx = 0; //(std::rand() % 200 - 100);
        float vy = 0; // (std::rand() % 200 - 100);
        float ax = 0.0f;
        float ay = 0.0f; 
        float m = 49.0f;
        sf::Color c = sf::Color((std::rand()%256), (std::rand()%256), (std::rand()%256));
        particles.emplace_back(x, y, vx, vy, ax, ay, m, c);
    }
}


void Simulator::run() {
   sf::Clock clock;
   while (window.isOpen()) {
      float elapsed = clock.getElapsedTime().asSeconds();
      
      if (elapsed >= Config::TIME_STEP) {
         clock.restart();
         Events();
         update(Config::TIME_STEP);
         render();
      } //else, sleep?
   }
}


void Simulator::Events() {
   sf::Event event;
   sf::Clock clock;
   while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
         window.close();
   }
}


void Simulator::update(float dt) {

   // add gravitational force betwen particles
   Physics::applyGravity(particles);

   // update postion
   for (Particle& p : particles) {
      p.update(dt);
   }
}


void Simulator::render() {
   window.clear();
   renderer.draw(particles);
   window.display();
}
