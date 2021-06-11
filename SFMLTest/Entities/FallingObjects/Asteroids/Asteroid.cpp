#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include "Asteroid.h"
#include "../../../Engine/GameConstants.h"
#include "../../../Engine/Universe.h"
#include <math.h>

Asteroid::Asteroid(Vec2D pos, bool isSwaying) : FallingObject(Type::Enemy, pos, 21, GameConstants::enemyMovSpeed) {
    initPosX = pos.x;
    Asteroid::isSwaying = isSwaying;
    frameCount += rand() % 20;
}

void Asteroid::update() {
    FallingObject::update();

    if (isSwaying) {
        pos.x = initPosX + 128 * sin(frameCount * 0.025f);
    }
}

void Asteroid::draw(sf::RenderWindow* window) {
    sf::CircleShape shape(size, 6);
    shape.setPosition(pos.x - size / 2, pos.y - size / 2);
    window->draw(shape);
}

void Asteroid::takeDamage(int amount) {
    remainingLives -= amount;
    if (remainingLives <= 0) {
        destroyConditionMet = true;

        Universe::getInstance().spawnCollectible(pos);
    }
}
