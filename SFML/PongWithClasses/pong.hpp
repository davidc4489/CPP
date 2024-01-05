#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "Pong"
#define POPPINS_PATH "Resources/Poppins.ttf"
#define BALL_INIT_POS_X WIN_WIDTH / 2
#define BALL_INIT_POS_Y WIN_HEIGHT / 2

using namespace sf;
using namespace std;

void LoadFont();

void setText(Text& txt, const std::string& str);

void checkButton();

void updateBall();