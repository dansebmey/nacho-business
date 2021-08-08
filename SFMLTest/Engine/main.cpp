#include "Universe.h"

int main() {
    std::cout << "Starting game..." << std::endl;

    Universe universe = Universe::getInstance();
    while (universe.exists()) {
        universe.update();
        universe.draw();
    }

    delete (&universe);

    return 0;
}