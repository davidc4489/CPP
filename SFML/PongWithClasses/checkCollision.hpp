#pragma once

#include "paddle.hpp"
#include "ball.hpp"
#include "pong.hpp"
#include "scoreboard.hpp"

class CheckCollision{
    public:
    CheckCollision() = default;
    void checkCollision(Scoreboard& scoreboard, Ball& ball, Paddle& leftRacket, Paddle& rightRacket, Text& txt) {
        float ballX = ball.getPositionX();
        float ballY = ball.getPositionY();
        float leftX = leftRacket.getPositionX();
        float leftY = leftRacket.getPositionY();
        float rightX = rightRacket.getPositionX();
        float rightY = rightRacket.getPositionY();
        float paddleWidth = leftRacket.getWidth();
        float paddleHeight = leftRacket.getHeight();

        // Check collision with the left paddle
        bool collideWithLeft = (ballX < leftX + paddleWidth &&
                                ballX > leftX &&
                                ballY < leftY + paddleHeight &&
                                ballY > leftY);

        // Check collision with the right paddle
        bool collideWithRight = (ballX > rightX - paddleWidth &&
                                ballX < rightX &&
                                ballY < rightY + paddleHeight &&
                                ballY > rightY);

        // Reverse direction if there is a collision
        if (collideWithLeft || collideWithRight) {
            ball.reverseXDirection();
        }

        if(ball.getPositionX() < 0) {
            scoreboard.increaseScorePlayer2();
            ball.setPosition(BALL_INIT_POS_X, BALL_INIT_POS_Y);
            setText(txt, to_string(scoreboard.getScorePlayer1()) + " | " + to_string(scoreboard.getScorePlayer2()));
        }

        if(ball.getPositionX() > WIN_WIDTH) {
            scoreboard.increaseScorePlayer1();
            ball.setPosition(BALL_INIT_POS_X, BALL_INIT_POS_Y);
            setText(txt, to_string(scoreboard.getScorePlayer1()) + " | " + to_string(scoreboard.getScorePlayer2()));
        }

        if(ball.getPositionY() > WIN_HEIGHT || ball.getPositionY() < 0) {
            ball.reverseYDirection();
        }
    }
};