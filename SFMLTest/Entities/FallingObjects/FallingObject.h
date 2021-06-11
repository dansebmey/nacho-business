#pragma once

#include "../GameObject.h"

class FallingObject : public GameObject {
    public:
        FallingObject(Type type, Vec2D vec2D, int size, float movSpeed);

        void update() override;
};


