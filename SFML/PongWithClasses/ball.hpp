#pragma once

#include "eventsHandler.hpp"
#include "paddle.hpp"
#include "pong.hpp"
#include <tgmath.h>
#include <iostream>

class Ball {
private:
    CircleShape shape;
    float speed;
    Vector2f direction;

public:
    Ball(float startX, float startY, float radius, float initialSpeed);

    void update();

    void draw(RenderWindow& window);

    void reverseXDirection();

    void reverseYDirection();

    float getPositionX() const;

    float getPositionY() const;

    void setPosition(float x, float y);

    float getDirectionX() const;

    float setDirectionX(float x);

    CircleShape getShape() const;
};