Particle_Simulation/        #   Root Project Folder
│── build/                  #   Build files
│── include/                #   Header files (.h)
│   ├── particle.h          #       Particle class declaration
│   ├── simulator.h         #       Simulator class declaration
│   ├── renderer.h          #       Renders class declaration
│   ├── physics.h           #       Physics class declaration 
│   ├── config.h            #       Config class declaration 
│── src/                    #   Source files (.cpp)
│   ├── main.cpp            #       Main
│   ├── particle.cpp        #       Particle class
│   ├── simulator.cpp       #       Simulator class definition (optional)
│   ├── renderer.cpp        #       Renderer class definition (handles SFML drawing)
│   ├── physics.cpp         #       Physics class (handles movement, collisions)
│   ├── config.cpp          #       Config class definition (contains constants like gravity, fps, etc.)
│── CMakeLists.txt          #   CMake build configuration
│── assets/                 #   Images/Sounds

