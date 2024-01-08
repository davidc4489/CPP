#include <SFML/Graphics.hpp>
#include "arkanoid.hpp"
#include "Ball/ball.hpp"
#include "Paddle/paddle.hpp"
#include "Blocks/blocks.hpp"
#include "EventChecker/EventChecker.hpp"
#include "EventHandler/EventHandler.hpp"
#include "CollisionsChecker/CollisionsChecker.hpp"
#include "Drawer/Drawer.hpp"
#include "ScoreBoard/ScoreBoard.hpp"
#include "LifesBoard/LifesBoard.hpp"
#include "TextFactory/TextFactory.hpp"
#include <iostream>

using namespace sf;

EventChecker eventChecker;
EventHandler eventHandler;
CollisionsChecker collisionsChecker;
RenderWindow window;
Text txt;
Drawer drawer;
Font font;

void loadFont();

LifesBoard lifesBoard(3, 64.1, 16.1, sf::Color::Green, 1.1, 13.1); // Number of lifes, boardWidth, boardHeight, boardColor, posX, posY
Paddle paddle(WIN_WIDTH/2, WIN_HEIGHT - 50, 150, 20, 1);
Ball ball(paddle.getPositionX() + (paddle.getWidth() / 2), paddle.getPositionY() - (paddle.getHeight()),10, 0.2, Color::Green);
Blocks blocks(6, 5, 100, 40, std::vector<Color> {Color::Red, Color::Green, Color::Blue});

int main(){
    loadFont();
    TextFactory startText("Press Space to Start", font, Color::White, 20, Vector2f{10,20});
    ScoreBoard scoreBoard(sf::Color::White, 20, 559, 5, font);  // Color, fontSize, posX, posY, font

    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Arkanoid", Style::Default);

    // setText(txt, to_string(scoreboard.getScorePlayer1()) + " | " + to_string(scoreboard.getScorePlayer2()));

    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            eventChecker.eventChecker(event, window);
        }

        eventHandler.eventHandler(eventChecker, ball, paddle, blocks, window);
        collisionsChecker.checkCollision(window, ball, paddle, blocks, lifesBoard, scoreBoard, eventChecker);

        window.clear(Color::Black);
        drawer.draw(window, blocks, paddle, ball, lifesBoard, scoreBoard, eventChecker, startText);
        window.display();
    }
    return 0;
}

void loadFont(){
    if(!font.loadFromFile(POPPINS_PATH)){
        std::cout << "Unable to load font" << std::endl;
    }
}

// void setText(Text& txt, const std::string& str){
//     txt.setFont(font);           
//     txt.setCharacterSize(26);       
//     txt.setFillColor(Color::White);   
//     txt.setPosition(WIN_WIDTH / 2 - 40, 10);
//     txt.setString(str);
// }

// void updateBall() {
//     ball.update();
//     checker.checkCollision(scoreboard, ball, leftRacket, rightRacket, txt);
// }


