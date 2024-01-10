#include "Drawer.hpp"

Drawer::Drawer(sf::RenderWindow& window, Blocks& blocks, Paddle& paddle, Ball& ball, LifesBoard& lifesBoard, ScoreBoard& scoreBoard, 
                EventChecker& eventChecker, Text& startText, Text& endText, Text& win)
: m_window(window),
m_blocks(blocks),
m_paddle(paddle),
m_ball(ball),
m_lifesBoard(lifesBoard),
m_scoreBoard(scoreBoard),
m_eventChecker(eventChecker),
m_startText(startText),
m_endText(endText),
m_win(win)
{}


void Drawer::draw(){
    m_window.clear(Color::Black);

    for (auto block : m_blocks.getBlocks())
    {
        m_window.draw(block);
    };

    m_window.draw(m_paddle.getShape());
    m_window.draw(m_ball.getShape());
    
    for (auto life : m_lifesBoard.lifes)
    {
        m_window.draw(life);
    };

    if(m_eventChecker.button.space == false){
        m_window.draw(m_startText);
    }

    if(m_eventChecker.button.gameOver == true){
        m_window.draw(m_endText);
    }

    if(m_eventChecker.button.win == true){
        m_window.draw(m_win);
    }

    // if (event.pressed.space == false)
    // {
    //     window.draw(txt);
    // }

    // if (event.pressed.gameOver == true)
    // {
    //     window.draw(gameOver);
    // }

    m_window.draw(m_scoreBoard.getStrScore());

    m_window.display();
};