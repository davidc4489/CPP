#include "Drawer.hpp"

void Drawer::draw(sf::RenderWindow& window, Blocks& blocks, Paddle& paddle, Ball& ball, 
                LifesBoard& lifesBoard, ScoreBoard& scoreBoard, EventChecker& eventChecker, TextFactory& text){
    window.clear();

    for (auto block : blocks.getBlocks())
    {
        window.draw(block);
    };

    window.draw(paddle.getShape());
    window.draw(ball.getShape());
    
    for (auto life : lifesBoard.lifes)
    {
        window.draw(life);
    };

    if(eventChecker.button.space == false){
        window.draw(text.text);
    }

    // if (event.pressed.space == false)
    // {
    //     window.draw(txt);
    // }

    // if (event.pressed.gameOver == true)
    // {
    //     window.draw(gameOver);
    // }

    window.draw(scoreBoard.getStrScore());

    window.display();
};