#pragma once

#include "eventsHandler.hpp"
#include "pong.hpp"

class Paddle {
private:
    RectangleShape shape;
    float speed;

public:
    Paddle(float startX, float startY, float width, float height, float initialSpeed)
        : speed(initialSpeed) {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(startX, startY);
    }

    void move(bool moveUp, bool moveDown) {
        if (moveUp) {
            shape.move(0, -speed);
            if(shape.getPosition().y < 0) {
                shape.setPosition(shape.getPosition().x, 0);
            }
        }

        if (moveDown) {
            shape.move(0, speed);
            if(shape.getPosition().y + shape.getSize().y > WIN_HEIGHT) {
                shape.setPosition(shape.getPosition().x, WIN_HEIGHT - shape.getSize().y);
            }
        }
    }
    
    float getPositionX() const {
        return shape.getPosition().x;
    }

    float getPositionY() const {
        return shape.getPosition().y;
    }

    float getWidth() const {
        return shape.getSize().x;
    }

    float getHeight() const {
        return shape.getSize().y;
    }

    RectangleShape getShape() const {
        return shape;
    }
};