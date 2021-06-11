#pragma once

#include "../FallingObject.h"

class Asteroid : public FallingObject {
    public:
        Asteroid(Vec2D pos, bool isSwaying);

        void draw(sf::RenderWindow* window) override;
        void update() override;

        void takeDamage(int amount);

    private:
        int remainingLives = 5;

        float initPosX;
        bool isSwaying;
};