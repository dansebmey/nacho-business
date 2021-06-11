#pragma once

#include "../GameObject.h"

class Projectile : public GameObject {
    public:
        Projectile(Vec2D pos);

        void update() override;
        void draw(sf::RenderWindow* window) override;
    protected:
        float mass = 10;

        void HandleCollisionDetection();
};


