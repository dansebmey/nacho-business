#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Engine/Vec2D.h"

class GameObject {
    public:
        enum Type { Player, Enemy, Projectile, Collectible, Particle };
        Type type;

        GameObject(Type type, Vec2D pos, int size, float movSpeed);

        virtual void update();
        virtual void draw(sf::RenderWindow* window) = 0;

        void applyForce(Vec2D force);
        Vec2D getPos();
        int getSize();

        bool isDestroyConditionMet();
        void setDestroyConditionMet();

    protected:
        int frameCount;

        Vec2D pos;
        Vec2D velocity {0,0};

        int size;
        int movSpeed = 100;
        float mass = 10;
        float frictionCoefficient = 0.18f;

        bool destroyConditionMet;
};


