#pragma once

#include "../Ball/ball.hpp"
#include "../Paddle/paddle.hpp"
#include "../Blocks/blocks.hpp"
#include "../LifesBoard/LifesBoard.hpp"
#include "../ScoreBoard/ScoreBoard.hpp"
#include "../EventChecker/EventChecker.hpp"
#include "../arkanoid.hpp"
#include "../Restart/Restart.hpp"

class CollisionsChecker{
    public:
    CollisionsChecker() = default;
    void checkCollision(RenderWindow& window, Ball& ball, Paddle& paddle, Blocks& blocks, LifesBoard& lifesBoard, ScoreBoard& scoreBoard, EventChecker& eventChecker, Restarter& restarter);
};