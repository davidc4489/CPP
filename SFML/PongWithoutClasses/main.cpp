#include "main.hpp"
#include "eventsHandler.hpp"
#include <tgmath.h>

RenderWindow window;
EventsHandler eventsHandler;
Font font;
Text txt;

int posXLeftRacket = 50;
int posXRightRacket = WIN_WIDTH - 70;
int posYLeftRacket = WIN_HEIGHT / 2;
int posYRightRacket = WIN_HEIGHT / 2;
int racketsSpeed = 1;
int racketsWidth = 20;
int racketsHeight = 150;

float ballSpeed = 0.2;
Vector2f ballDirection = Vector2f(1.5f, 2);
float ballPosX = BALL_INIT_POS_X;
float ballPosY = BALL_INIT_POS_Y;

int scoreGamer_1 = 0;
int scoreGamer_2 = 0;

int main(){
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong", Style::Default);

    LoadFont();
    setText(txt, to_string(scoreGamer_1) + " | " + to_string(scoreGamer_2));

    CircleShape ball(15);
    ball.setPosition(ballPosX, ballPosY);

    RectangleShape leftRacket(Vector2f(racketsWidth, racketsHeight));
    leftRacket.setPosition(posXLeftRacket, posYLeftRacket);
    RectangleShape rightRacket(Vector2f(racketsWidth, racketsHeight));
    rightRacket.setPosition(posXRightRacket, posYRightRacket);

    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            eventsHandler.eventHandler(event, window);
        }

        checkButton();
        leftRacket.setPosition(posXLeftRacket, posYLeftRacket);
        rightRacket.setPosition(posXRightRacket, posYRightRacket);

        updateBall();
        ball.setPosition(ballPosX, ballPosY);

        window.clear(Color::Black);
        window.draw(leftRacket);
        window.draw(rightRacket);
        window.draw(ball);
        window.draw(txt);
        window.display();
    }
    return 0;
}

void LoadFont(){
    if(!font.loadFromFile(POPPINS_PATH)){
        std::cout << "Unable to load font" << std::endl;
    }
}

void setText(Text& txt, const std::string& str){
    txt.setFont(font);           
    txt.setCharacterSize(26);       
    txt.setFillColor(Color::White);   
    txt.setPosition(WIN_WIDTH / 2 - 40, 10);
    txt.setString(str);
}

void checkButton(){
    // Left Racket
    if(eventsHandler.getButton().up == true){
        posYLeftRacket -= racketsSpeed;
        if(posYLeftRacket <= 0){
            posYLeftRacket = 0;
        }
    }

    if(eventsHandler.getButton().down == true){
        posYLeftRacket += racketsSpeed;
        if(posYLeftRacket + racketsHeight > WIN_HEIGHT){
            posYLeftRacket = WIN_HEIGHT - racketsHeight;
        }
    }

    // Right Racket
    if(eventsHandler.getButton().up_2 == true){
        posYRightRacket -= racketsSpeed;
        if(posYRightRacket <= 0){
            posYRightRacket = 0;
        }
    }

    if(eventsHandler.getButton().down_2 == true){
        posYRightRacket += racketsSpeed;
        if(posYRightRacket + racketsHeight > WIN_HEIGHT){
            posYRightRacket = WIN_HEIGHT - racketsHeight;
        }
    }

    if(eventsHandler.getButton().escape == true){
        window.close();
    }

}

void updateBall() {
    ballPosX += ballDirection.x * ballSpeed;
    ballPosY += ballDirection.y * ballSpeed;

    if ((ballPosX < posXLeftRacket + racketsWidth &&
         ballPosX > posXLeftRacket &&
         ballPosY < posYLeftRacket + racketsHeight &&
         ballPosY > posYLeftRacket) ||
        (ballPosX > posXRightRacket - racketsWidth &&
         ballPosX < posXRightRacket &&
         ballPosY < posYRightRacket + racketsHeight &&
         ballPosY > posYRightRacket)) {
        ballDirection.x = -ballDirection.x;
    }

    if(ballPosX < 0){
        scoreGamer_2++;
        ballPosX = BALL_INIT_POS_X;
        ballPosY = BALL_INIT_POS_Y;
        ballDirection.x = fabs(ballDirection.x);
        ballDirection.y = -ballDirection.y;
        setText(txt, to_string(scoreGamer_1) + " | " + to_string(scoreGamer_2));
    }

    if(ballPosX > WIN_WIDTH){
        scoreGamer_1++;
        ballPosX = BALL_INIT_POS_X;
        ballPosY = BALL_INIT_POS_Y;
        ballDirection.x = -ballDirection.x;
        ballDirection.y = -ballDirection.y;
        setText(txt, to_string(scoreGamer_1) + " | " + to_string(scoreGamer_2));
    }

    if(ballPosY < 0 || ballPosY > WIN_HEIGHT){
        ballDirection.y = -ballDirection.y;
    }
    
}
