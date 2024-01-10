#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
    CircleShape shape;
    float speed;
    Vector2f direction;

public:
    Ball(float startX, float startY, float radius, float initialSpeed, Color color);

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

    float getRadius() const;
};