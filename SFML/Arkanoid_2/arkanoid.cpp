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
#include "Restart/Restart.hpp"
#include "Button/Button.hpp"
#include "TopTen/TopTen.hpp"
#include <iostream>

using namespace sf;

EventChecker eventChecker;
EventHandler eventHandler;
CollisionsChecker collisionsChecker;
RenderWindow window;
Text txt;
Font font;
TextFactory textFactory;


void loadFont();

LifesBoard lifesBoard(3, 64.1, 16.1, sf::Color::Green, WIN_WIDTH - 10, 10); // Number of lifes, boardWidth, boardHeight, boardColor, posX, posY
Paddle paddle(WIN_WIDTH/2, WIN_HEIGHT - 50, 150, 20, 1);
Ball ball(paddle.getPositionX() + (paddle.getWidth() / 2), paddle.getPositionY() - (paddle.getHeight()),10, 0.2, Color::Green);
Blocks blocks(3, 5, 100, 40, std::vector<Color> {Color::Red, Color::Green, Color::Blue});

int main(){
    loadFont();
    TopTen topTen(font);
    ButtonFactory playButton(200, 275, 100, 50, "Play", font);
    ButtonFactory quitButton(500, 275, 100, 50, "Quit", font);
    std::vector<ButtonFactory> buttons = {playButton, quitButton};
    Text startText = textFactory.createText("Press Space to Start", font, Color::White, 20, Vector2f{10,40});
    Text gameOverText = textFactory.createText("Game Over", font, Color::Red, 20, Vector2f{WIN_HEIGHT / 2, (WIN_WIDTH / 2) - 30});
    Text winner = textFactory.createText("You Win", font, Color::Blue, 20, Vector2f{WIN_HEIGHT / 2, (WIN_WIDTH / 2) - 30});
    ScoreBoard scoreBoard(sf::Color::White, 20, 10, 10, font);  // Color, fontSize, posX, posY, font
    Drawer drawer(window, blocks, paddle, ball, lifesBoard, scoreBoard, eventChecker, startText, gameOverText, winner, buttons, topTen);
    Restarter restarter(paddle, ball, lifesBoard, scoreBoard, eventChecker, drawer);
    GameOver gameOver;

    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Arkanoid", Style::Default);

    // setText(txt, to_string(scoreboard.getScorePlayer1()) + " | " + to_string(scoreboard.getScorePlayer2()));

    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
            eventChecker.eventChecker(event, window, buttons);
        }

        eventHandler.eventHandler(eventChecker, ball, paddle, blocks, window, restarter, gameOver);
        collisionsChecker.checkCollision(window, ball, paddle, blocks, lifesBoard, scoreBoard, eventChecker, restarter);

        drawer.draw();
        // window.draw(topTen.topTen[0]);
        // window.display();
    }
    return 0;
}

void loadFont(){
    if(!font.loadFromFile(POPPINS_PATH)){
        std::cout << "Unable to load font" << std::endl;
    }
}