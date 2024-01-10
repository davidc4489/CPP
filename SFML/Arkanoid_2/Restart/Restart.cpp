#include "Restart.hpp"

Restarter::Restarter(Paddle& paddle, Ball& ball, LifesBoard& lifesBoard,
                ScoreBoard& scoreBoard, EventChecker& eventChecker, Drawer& drawer)
    :m_paddle(paddle),
    m_ball(ball),
    m_lifesBoard(lifesBoard),
    m_scoreBoard(scoreBoard),
    m_eventChecker(eventChecker),
    m_drawer(drawer)
    {};

void Restarter::restart(Blocks& blocks){
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 5) {
        m_ball.setPosition(m_paddle.getPositionX() + (m_paddle.getWidth() / 2), m_paddle.getPositionY() - (m_paddle.getHeight()));
        m_scoreBoard.resetScore();
        m_eventChecker.button.space = false;
        m_drawer.draw();
    };
    m_eventChecker.button.win = false;
    blocks.getBlocks().clear();
    blocks.fillVectorBlocks(blocks.rows, blocks.cols, blocks.width, blocks.height, blocks.colors);
}