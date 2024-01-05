#include "ball.hpp"

Ball::Ball(float startX, float startY, float radius, float initialSpeed)
    : speed(initialSpeed), direction(1.5f, 2) {
    shape.setRadius(radius);
    shape.setPosition(startX, startY);
}

void Ball::update() {
    shape.move(direction.x * speed, direction.y * speed);
}

void Ball::reverseXDirection() {
    direction.x = -direction.x;
}

void Ball::reverseYDirection() {
    direction.y = -direction.y;
}

float Ball::getPositionX() const {
    return shape.getPosition().x;
}

float Ball::getPositionY() const {
    return shape.getPosition().y;
}

void Ball::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

float Ball::getDirectionX() const {
    return direction.x;
}

float Ball::setDirectionX(float x) {
    return direction.x = x;
}

CircleShape Ball::getShape() const {
    return shape;
}