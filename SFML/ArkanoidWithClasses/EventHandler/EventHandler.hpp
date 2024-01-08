#pragma once

#include "../EventChecker/EventChecker.hpp"
#include "../Paddle/paddle.hpp"
#include "../Blocks/blocks.hpp"
#include "../Ball/ball.hpp"

class EventHandler{
    public:
    EventHandler() = default;
    void eventHandler(EventChecker& eventChecker, Ball& ball, Paddle& paddle, Blocks& blocks ,Window& window);
};