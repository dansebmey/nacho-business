#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "../FallingObject.h"

class Particle : public FallingObject {

    public:
        Particle(Vec2D vec2D);
        void draw(sf::RenderWindow* window);
};