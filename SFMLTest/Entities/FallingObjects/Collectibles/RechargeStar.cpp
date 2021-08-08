#include <SFML/Graphics/CircleShape.hpp>
#include "RechargeStar.h"
#include "../../../Engine/Universe.h"
#include <math.h>
#include <algorithm>

RechargeStar::RechargeStar(Vec2D pos, float movSpeed) : Star(pos, movSpeed) {
    pointValue = 50;
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

    int comboPoints = std::min(Universe::getInstance().consecutiveBigStarPickups * 10, 100);
    Universe::getInstance().increasePlayerScore(comboPoints);

    Universe::getInstance().consecutiveBigStarPickups++;
}

void RechargeStar::AssignSpecificScorePoints() {
    int comboPoints = std::min(Universe::getInstance().consecutiveBigStarPickups * 10, 100);
    Universe::getInstance().increaseBigStarPoints(pointValue + comboPoints);
}

void RechargeStar::OnOutOfScreen() {
    Star::OnOutOfScreen();
    Universe::getInstance().consecutiveBigStarPickups = 0;
}
