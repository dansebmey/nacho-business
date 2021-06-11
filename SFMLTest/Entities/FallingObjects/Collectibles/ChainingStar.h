#pragma once

#include "Star.h"

class ChainingStar : public Star {
    public:
        ChainingStar(Vec2D pos, float movSpeed);

        void draw(sf::RenderWindow *window) override;

        void onPickup() override;
        void spawnNewChainStar();
};