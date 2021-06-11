#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Player.h"
#include "Projectiles/Projectile.h"
#include "../Engine/Universe.h"
#include "../Engine/GameConstants.h"
#include "../Engine/DebugUtil.h"
#include "FallingObjects/Collectibles/Star.h"

Player::Player(Vec2D pos) : GameObject(Type::Player, pos, 25, GameConstants::playerMovSpeed) {

}

void Player::update() {
    GameObject::update();

    handleMovement();
    handleScreenWrapping();
    handleEnergyDepletion();
    handleCollisionDetection();

    framesSinceLastShot++;
    if (autofireActive) {
        fire();
    }
}

void Player::draw(sf::RenderWindow* window) {
    sf::CircleShape triangle(size, 3);
    triangle.setPosition(pos.x - size / 2, pos.y - size / 2);
    triangle.setFillColor(sf::Color::Green);
    window->draw(triangle);
}

void Player::fire() {
    if (framesSinceLastShot >= 6 && energy >= projectileEnergyCost) {
        Universe::getInstance().spawnObject(new class Projectile(Vec2D(pos.x - size * 0.75f, pos.y)));
        Universe::getInstance().spawnObject(new class Projectile(Vec2D(pos.x + size * 0.75f, pos.y)));
        framesSinceLastShot = 0;
        energy -= projectileEnergyCost;
    }
}

void Player::setShooting(bool toggle) {
    fire();
    framesSinceLastShot = 0;
    autofireActive = toggle;
}

void Player::setNitroThrustersActive(bool toggle) {
    movSpeed = GameConstants::playerMovSpeed * (toggle && energy > 0.025f ? 2 : 1);
}

void Player::handleMovementInput(int dir) {
    movDir = dir;
}

void Player::gainEnergy(float amount) {
    energy += amount;
    if (energy > 1) {
        energy = 1;
    }
}

void Player::handleScreenWrapping() {
    if (pos.x < 0) {
        pos.x = GameConstants::screenWidth;
    }
    else if (pos.x > GameConstants::screenWidth) {
        pos.x = 0;
    }
}

void Player::handleMovement() {
    if (movDir != 0) {
        playerVelocity += movDir * acceleration;
        if (playerVelocity > 1) {
            playerVelocity = 1;
        } else if (playerVelocity < -1) {
            playerVelocity = -1;
        }
    } else {
        if (playerVelocity > 0) {
            playerVelocity -= acceleration;
        } else if (playerVelocity < 0) {
            playerVelocity += acceleration;
        }
        if (playerVelocity > 0 && playerVelocity < acceleration) {
            playerVelocity = 0;
        }
    }
    applyForce(Vec2D(playerVelocity * (movSpeed / mass), 0));
}

void Player::handleEnergyDepletion() {
    if (energy > 0 && movSpeed > GameConstants::playerMovSpeed) {
        energy -= nitroBoostEnergyCost;
        if (energy < energyRegenSpeed) {
            setNitroThrustersActive(false);
        }
    } else if (energy < 1 && movSpeed == GameConstants::playerMovSpeed) {
        energy += energyRegenSpeed;
    }
    Universe::getInstance().hud->playerEnergy = energy;
}

void Player::takeDamage(int amount) {
    livesRemaining -= amount;
    if (livesRemaining <= 0) {
        Universe::getInstance().currentState = Universe::State::GameOver;
        destroyConditionMet = true;
    }
    Universe::getInstance().hud->playerHealth = livesRemaining;
}

void Player::handleCollisionDetection() {
    std::vector<GameObject*> gameObjects = Universe::getInstance().getGameObjects();

    for (int i = 0; i < gameObjects.size(); i++) {
        GameObject* other = gameObjects[i];
        if (other->type == Type::Collectible) {
            if (Vec2D::distanceBetween(pos, other->getPos()) < (size * 0.5f) + (other->getSize() * 0.5f)) {
                Star* star = dynamic_cast<Star*>(other);
                star->onPickup();
                star->setDestroyConditionMet();

                if (Universe::getInstance().getPlayer()->energy > 1) {
                    Universe::getInstance().getPlayer()->energy = 1;
                }
            }
        } else if (other->type == Type::Enemy) {
            if (Vec2D::distanceBetween(pos, other->getPos()) < (size * 0.5f) + (other->getSize() * 0.5f)) {
                Universe::getInstance().getPlayer()->takeDamage(1);
                other->setDestroyConditionMet();
            }
        }
    }
}