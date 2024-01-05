#include "pong.hpp"
#include "eventsHandler.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "checkCollision.hpp"
#include "scoreboard.hpp"
#include "drawer.hpp"
#include <tgmath.h>

RenderWindow window;
EventsHandler eventsHandler;
Font font;
Text txt;
Drawer drawer;

Scoreboard scoreboard;
CheckCollision checker;

Paddle leftRacket(50, WIN_HEIGHT / 2, 20, 150, 1);
Paddle rightRacket(WIN_WIDTH - 70, WIN_HEIGHT / 2, 20, 150, 1);
Ball ball(BALL_INIT_POS_X, BALL_INIT_POS_Y, 15, 0.2);

int main(){
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong", Style::Default);

    LoadFont();
    setText(txt, to_string(scoreboard.getScorePlayer1()) + " | " + to_string(scoreboard.getScorePlayer2()));

    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            eventsHandler.eventHandler(event, window);
        }

        checkButton();

        updateBall();

        window.clear(Color::Black);
        drawer.draw(leftRacket.getShape(), window);
        drawer.draw(rightRacket.getShape(), window);
        drawer.draw(ball.getShape(), window);
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
        leftRacket.move(true, false);
    }

    if(eventsHandler.getButton().down == true){
        leftRacket.move(false, true);
    }

    // Right Racket
    if(eventsHandler.getButton().up_2 == true){
        rightRacket.move(true, false);
    }

    if(eventsHandler.getButton().down_2 == true){
        rightRacket.move(false, true);
    }

    if(eventsHandler.getButton().escape == true){
        window.close();
    }
}

void updateBall() {
    ball.update();
    checker.checkCollision(scoreboard, ball, leftRacket, rightRacket, txt);
}
