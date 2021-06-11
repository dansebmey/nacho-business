#pragma once

#include "../FallingObject.h"

class Star : public FallingObject {

    public:
        Star(Vec2D pos, float movSpeed);

        void draw(sf::RenderWindow* window) override;
        void update() override;

        int getPointValue();

        float getRechargeValue();

        virtual void onPickup();

    protected:
        int pointValue;
        float rechargeValue;
};