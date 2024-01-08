#pragma once

#include "../Blocks/blocks.hpp"
#include "../Paddle/paddle.hpp"
#include "../Ball/ball.hpp"
#include "../ScoreBoard/ScoreBoard.hpp"
#include "../LifesBoard/LifesBoard.hpp"
#include "../EventChecker/EventChecker.hpp"
#include "../TextFactory/TextFactory.hpp"

class Drawer
{
public:
    Drawer() = default;
    void draw(sf::RenderWindow& window, Blocks& blocks, Paddle& paddle, Ball& ball, LifesBoard& lifesBoard, ScoreBoard& scoreBoard, EventChecker& eventChecker, TextFactory& text);
};