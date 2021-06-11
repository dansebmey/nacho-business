#include <SFML/Graphics/CircleShape.hpp>
#include "Projectile.h"
#include "../../Engine/GameConstants.h"
#include "../../Engine/Universe.h"
#include "../FallingObjects/Asteroids/Asteroid.h"

Projectile::Projectile(Vec2D pos) : GameObject(Type::Projectile, Vec2D(pos.x + 7, pos.y), 15, GameConstants::projectileMovSpeed) {

}

void Projectile::update() {
    GameObject::update();

    applyForce(Vec2D(0, -1000.0f / mass));
    HandleCollisionDetection();
    if (pos.y < 0) {
        destroyConditionMet = true;
    }
}

void Projectile::draw(sf::RenderWindow* window) {
    sf::CircleShape circle(5, 4);
    circle.setPosition(pos.x, pos.y);
    window->draw(circle);
}

void Projectile::HandleCollisionDetection() {
    std::vector<GameObject*> gameObjects = Universe::getInstance().getGameObjects();

    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject *other = gameObjects[i];
        if (other->type == Type::Enemy) {
            if (Vec2D::distanceBetween(pos, other->getPos()) < (size * 0.5f) + (other->getSize() * 0.5f)) {
                Asteroid* asteroid = dynamic_cast<Asteroid*>(other);
                asteroid->takeDamage(1);
                destroyConditionMet = true;
            }
        }
    }
}