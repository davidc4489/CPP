#include "Drawer.hpp"

Drawer::Drawer(sf::RenderWindow& window, Blocks& blocks, Paddle& paddle, Ball& ball, LifesBoard& lifesBoard, ScoreBoard& scoreBoard, 
                EventChecker& eventChecker, Text& startText, Text& endText, Text& win, std::vector<ButtonFactory>& buttons, TopTen& topTenVector)
: m_window(window),
m_blocks(blocks),
m_paddle(paddle),
m_ball(ball),
m_lifesBoard(lifesBoard),
m_scoreBoard(scoreBoard),
m_eventChecker(eventChecker),
m_startText(startText),
m_endText(endText),
m_win(win),
m_buttons(buttons),
m_topTen(topTenVector)
{}


void Drawer::draw(){
    m_window.clear(Color::Black);

    if(m_eventChecker.button.play == true && m_eventChecker.button.escape == false){

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

        m_window.draw(m_scoreBoard.getStrScore());

    }

    else{
        m_eventChecker.button.play = false;
        m_window.draw(m_buttons[0].getShape());
        m_window.draw(m_buttons[1].getShape());
        m_window.draw(m_buttons[0].getLabel());
        m_window.draw(m_buttons[1].getLabel());
            for(int i = 0; i <10; i++){
        // m_window.draw(m_topTen.topTen[0]);
    }
    }

    m_window.display();
};