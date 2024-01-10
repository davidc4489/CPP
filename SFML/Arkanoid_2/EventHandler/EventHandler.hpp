#pragma once

#include "../EventChecker/EventChecker.hpp"
#include "../Paddle/paddle.hpp"
#include "../Blocks/blocks.hpp"
#include "../Ball/ball.hpp"
#include "../Restart/Restart.hpp"
#include "../GameOver/GameOver.hpp"

class EventHandler{
public:
    EventHandler() = default;
    void eventHandler(EventChecker& eventChecker, Ball& ball, Paddle& paddle, Blocks& blocks ,RenderWindow& window, Restarter& restarter, GameOver& gameOver);
};