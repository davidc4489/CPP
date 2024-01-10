#pragma once

#include <SFML/Graphics.hpp>
#include "../Ball/ball.hpp"
#include "../Paddle/paddle.hpp"
#include "../Blocks/blocks.hpp"
#include "../EventChecker/EventChecker.hpp"
#include "../Drawer/Drawer.hpp"
#include "../ScoreBoard/ScoreBoard.hpp"
#include "../LifesBoard/LifesBoard.hpp"
#include "../TextFactory/TextFactory.hpp"

using namespace sf;

class Restarter{
public:
    Restarter(Paddle& paddle, Ball& ball, LifesBoard& lifesBoard,
                ScoreBoard& scoreBoard, EventChecker& eventChecker, Drawer& drawer);
    void restart(Blocks& blocks);
    Paddle& m_paddle;
    Ball& m_ball;
    LifesBoard& m_lifesBoard;
    ScoreBoard& m_scoreBoard;
    EventChecker& m_eventChecker;
    Drawer& m_drawer;
};