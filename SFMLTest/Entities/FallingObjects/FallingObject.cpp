#include "FallingObject.h"
#include "../../Engine/GameConstants.h"

FallingObject::FallingObject(GameObject::Type type, Vec2D vec2D, int size, float movSpeed): GameObject(type, vec2D, size, movSpeed) {

}

void FallingObject::update() {
    GameObject::update();

    applyForce(Vec2D(0, movSpeed / mass));
    if (pos.y > GameConstants::screenHeight) {
        destroyConditionMet = true;
    }
}