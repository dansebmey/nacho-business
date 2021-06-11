#include <SFML/Graphics/CircleShape.hpp>
#include "RechargeStar.h"
#include "../../../Engine/Universe.h"
#include <math.h>

RechargeStar::RechargeStar(Vec2D pos, float movSpeed) : Star(pos, movSpeed) {
    pointValue = 5;
    rechargeValue = 0.25f;
    size *= 1.5f;
}

void RechargeStar::draw(sf::RenderWindow *window) {
    sf::CircleShape shape(size, 16);
    shape.setFillColor(sf::Color(255, 127 + 127 * sin(frameCount * 0.1f), 0));
    shape.setPosition(pos.x, pos.y);
    window->draw(shape);
}

void RechargeStar::onPickup() {
    Star::onPickup();
}
