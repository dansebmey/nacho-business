#include <SFML/Graphics/CircleShape.hpp>
#include "ChainingStar.h"
#include "../../../Engine/Universe.h"
#include "../../../Engine/GameConstants.h"
#include <math.h>

ChainingStar::ChainingStar(Vec2D pos, float movSpeed) : Star(pos, movSpeed) {
    pointValue = 5;
    rechargeValue = 0.25f;
    size *= 1.5f;
}

void ChainingStar::draw(sf::RenderWindow *window) {
    sf::CircleShape shape(size, 16);
    float intensity = 127 + 127 * sin(frameCount * 0.1f);
    shape.setFillColor(sf::Color(intensity, 255, 255));
    shape.setPosition(pos.x, pos.y);
    window->draw(shape);
}

void ChainingStar::onPickup() {
    Star::onPickup();
    spawnNewChainStar();
}

void ChainingStar::spawnNewChainStar() {
    int dir = -1 + (rand() % 3);
    Universe::getInstance().spawnObject(new ChainingStar(Vec2D(pos.x + dir * 16, pos.y - 48), GameConstants::enemyMovSpeed));
}
