#pragma once

#include "Star.h"

class RechargeStar : public Star {
    public:
        RechargeStar(Vec2D pos, float movSpeed);

        void draw(sf::RenderWindow *window) override;

        void onPickup() override;
};


