#include <iostream>
#include <vector>
#include "particle.h"


int main() {

    particle p1(0.0, 0.0, 0.0, 0.0, 0.0, -9.8);

    bool isRunning = true;

    while (isRunning) {
        p1.update(0.1);
        p1.print_pos();
    }
}
