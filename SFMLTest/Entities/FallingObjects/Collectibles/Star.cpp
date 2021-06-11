#include "Star.h"
#include "../../../Engine/GameConstants.h"
#include "../../../Engine/Universe.h"
#include <SFML/Graphics/CircleShape.hpp>

Star::Star(Vec2D pos, float movSpeed) : FallingObject(Type::Collectible, pos, 7, movSpeed) {
    pointValue = 1;
    rechargeValue = 0.1f;
}

void Star::update() {
    FallingObject::update();

    if (pos.y > GameConstants::screenHeight) {
        destroyConditionMet = true;
    }
}

void Star::draw(sf::RenderWindow* window) {
    sf::CircleShape shape(size, 16);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(pos.x, pos.y);
    window->draw(shape);
}

int Star::getPointValue() {
    return pointValue;
}

float Star::getRechargeValue() {
    return rechargeValue;
}

void Star::onPickup() {
    Universe::getInstance().increasePlayerScore(pointValue);
    Universe::getInstance().getPlayer()->gainEnergy(rechargeValue);
}