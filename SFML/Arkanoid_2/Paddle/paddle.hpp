#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
private:
    RectangleShape shape;
    float speed;

public:
    Paddle(float startX, float startY, float width, float height, float initialSpeed);
    void move(bool moveRight, bool moveLeft);
    
    float getPositionX() const;

    float getPositionY() const;

    float getWidth() const;

    float getHeight() const;

    RectangleShape getShape() const;
};