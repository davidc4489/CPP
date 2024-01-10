#include "paddle.hpp"
#include "../arkanoid.hpp"

Paddle::Paddle(float startX, float startY, float width, float height, float initialSpeed)
    : speed(initialSpeed) {
    shape.setSize(Vector2f(width, height));
    shape.setPosition(startX, startY);
}

void Paddle::move(bool moveRight, bool moveLeft) {
    if (moveLeft) {
        shape.move(-speed, 0);
        if(shape.getPosition().x < 0) {
            shape.setPosition(0, shape.getPosition().y);
        }
    }

    if (moveRight) {
        shape.move(speed, 0);
        if(shape.getPosition().x + shape.getSize().x > WIN_WIDTH) {
            shape.setPosition(WIN_WIDTH - shape.getSize().x, shape.getPosition().y);
        }
    }
}

float Paddle::getPositionX() const {
    return shape.getPosition().x;
}

float Paddle::getPositionY() const {
    return shape.getPosition().y;
}

float Paddle::getWidth() const {
    return shape.getSize().x;
}

float Paddle::getHeight() const {
    return shape.getSize().y;
}

RectangleShape Paddle::getShape() const {
    return shape;
}