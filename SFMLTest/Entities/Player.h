#pragma once

#include "GameObject.h"

class Player : public GameObject {
    public:
        Player(Vec2D pos);

        void setShooting(bool toggle);
        void setNitroThrustersActive(bool toggle);

        void handleMovementInput(int dir);
        void takeDamage(int amount);
        void gainEnergy(float amount);
    private:
        int livesRemaining = 3;
        float energy = 1;

        int movDir = 0;
        float acceleration = 0.1f;
        float playerVelocity;

        bool autofireActive;
        void update() override;
        void draw(sf::RenderWindow* window) override;

        void fire();
        int framesSinceLastShot;

        void handleScreenWrapping();
        void handleMovement();

        void handleEnergyDepletion();

        float energyRegenSpeed = 0.0002f;
        float projectileEnergyCost = 0.01f;
        float nitroBoostEnergyCost = 0.02f;

        void handleCollisionDetection();
};