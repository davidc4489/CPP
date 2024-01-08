#include "CollisionsChecker.hpp"

void CollisionsChecker::checkCollision(RenderWindow& window, Ball& ball, Paddle& paddle, Blocks& blocks, 
                                       LifesBoard& lifesBoard, ScoreBoard& scoreBoard, EventChecker& eventChecker) {
    float ballX = ball.getPositionX();
    float ballY = ball.getPositionY();
    float paddleX = paddle.getPositionX();
    float paddleY = paddle.getPositionY();
    float paddleWidth = paddle.getWidth();
    float paddleHeight = paddle.getHeight();
    std::vector<RectangleShape>& currentBlocks = blocks.getBlocks();

    // Check collision with the paddle
    bool collideWithPaddle = (ballX < paddleX + paddleWidth &&
                            ballX > paddleX &&
                            ballY < paddleY + paddleHeight &&
                            ballY > paddleY);

    // Reverse direction if there is a collision
    if (collideWithPaddle) {
        ball.reverseYDirection();
    }

    // if(ball.getPositionY() > WIN_HEIGHT) {
    //     // scoreboard.increaseScorePlayer2();
    //     ball.setPosition(BALL_INIT_POS_X, BALL_INIT_POS_Y);
    //     ball.reverseYDirection();
    // }

    if(ball.getPositionY() < 0) {
        ball.reverseYDirection();
    }

    if(ball.getPositionX() > WIN_WIDTH || ball.getPositionX() < 0) {
        ball.reverseXDirection();
    }

    for (long unsigned int i = 0; i < currentBlocks.size(); i++) {
        float blockX = currentBlocks[i].getPosition().x;
        float blockY = currentBlocks[i].getPosition().y;
        float blockWidth = currentBlocks[i].getSize().x;
        float blockHeight = currentBlocks[i].getSize().y;
        
        bool collideWithBlock = (ballX >= blockX &&
                                ballX <= blockX + blockWidth &&
                                ballY >= blockY &&
                                ballY <= blockY + blockHeight);

        // Reverse direction if there is a collision
        if (collideWithBlock) {
            currentBlocks.erase(currentBlocks.begin() + i);
            scoreBoard.incrementScore(10);
            ball.reverseYDirection();
        }
    }

    if (ballY >= WIN_HEIGHT){
        if (lifesBoard.lifes.size() > 0){
            lifesBoard.kill();
            ball.setPosition(paddleX + (paddleWidth / 2), paddleY - (paddleHeight));
            eventChecker.button.space = false;
        }
        else{
            eventChecker.button.space = false;
            // eventChecker.button.gameOver = true;
        }
    }

    (void)window;

}