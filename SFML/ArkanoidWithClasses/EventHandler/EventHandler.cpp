#include "EventHandler.hpp"

void EventHandler::eventHandler(EventChecker& eventChecker, Ball& ball, Paddle& paddle, Blocks& blocks, Window& window){
    if(eventChecker.getButton().right == true && eventChecker.button.space == true){
        paddle.move(true, false);
    }

    if(eventChecker.getButton().left == true && eventChecker.button.space == true){
        paddle.move(false, true);
    }

    if(eventChecker.getButton().escape == true){
        window.close();
    }

    if(eventChecker.getButton().space == true && eventChecker.getButton().spacer == true){
        // eventChecker.button.spacer = false;
        ball.update();
    }
}