#include "Particle.h"

Particle::Particle(Vec2D pos) : FallingObject(Type::Particle, pos, 3, 200 + rand() % 400) {

}

void Particle::draw(sf::RenderWindow *window) {
    sf::CircleShape shape(size, 4);
    shape.setFillColor(sf::Color(255, 255, 255, 127));
    shape.setPosition(pos.x, pos.y);
    window->draw(shape);
}