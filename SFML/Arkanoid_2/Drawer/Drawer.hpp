#pragma once

#include "../Blocks/blocks.hpp"
#include "../Paddle/paddle.hpp"
#include "../Ball/ball.hpp"
#include "../ScoreBoard/ScoreBoard.hpp"
#include "../LifesBoard/LifesBoard.hpp"
#include "../EventChecker/EventChecker.hpp"
#include "../TextFactory/TextFactory.hpp"
#include "../Button/Button.hpp"
#include "../TopTen/TopTen.hpp"

class Drawer
{
public:
    Drawer(sf::RenderWindow& window, Blocks& blocks, Paddle& paddle, Ball& ball, LifesBoard& lifesBoard, 
        ScoreBoard& scoreBoard, EventChecker& eventChecker, Text& startText, Text& endText, Text& win,
        std::vector<ButtonFactory>& buttons, TopTen& topTen);
    sf::RenderWindow& m_window;
    Blocks& m_blocks; 
    Paddle& m_paddle; 
    Ball& m_ball; 
    LifesBoard& m_lifesBoard; 
    ScoreBoard& m_scoreBoard; 
    EventChecker& m_eventChecker; 
    Text& m_startText; 
    Text& m_endText; 
    Text& m_win;
    std::vector<ButtonFactory>& m_buttons;
    TopTen& m_topTen;

    void draw();
};