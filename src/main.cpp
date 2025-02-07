#include "simulator.h"


int main() {
    int n;
    std::cout << "How many particles? ";
    std::cin >> n;
    Simulator simulator(n);
    simulator.run();
    return 0;
}
