#include "EventHandler.hpp"

void EventHandler::eventHandler(EventChecker& eventChecker, Ball& ball, Paddle& paddle, Blocks& blocks, RenderWindow& window, Restarter& restarter, GameOver& gameOver){
    if(eventChecker.getButton().right == true && eventChecker.button.space == true){
        paddle.move(true, false);
    }

    if(eventChecker.getButton().left == true && eventChecker.button.space == true){
        paddle.move(false, true);
    }

    if(eventChecker.getButton().space == true && eventChecker.getButton().spacer == true){
        ball.update();
    }

    if(eventChecker.getButton().gameOver == true){
        gameOver.gameOver(window);
    }

}