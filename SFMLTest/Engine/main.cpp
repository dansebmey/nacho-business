#include "Universe.h"

int main() {
    Universe universe = Universe::getInstance();
    while (universe.exists()) {
        universe.update();
        universe.draw();
    }

    return 0;
}

