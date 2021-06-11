#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include "GameObject.h"

GameObject::GameObject(Type type, Vec2D pos, int size, float movSpeed) : type(type), pos(pos.x, pos.y), size(size), movSpeed(movSpeed) {

}

void GameObject::applyForce(Vec2D force) {
    velocity += force;
}

Vec2D GameObject::getPos() {
    return pos;
}

void GameObject::update() {
    frameCount++;

    velocity *= frictionCoefficient;
    pos += velocity;
}

int GameObject::getSize() {
    return size;
}

bool GameObject::isDestroyConditionMet() {
    return destroyConditionMet;
}

void GameObject::setDestroyConditionMet() {
    destroyConditionMet = true;
}
