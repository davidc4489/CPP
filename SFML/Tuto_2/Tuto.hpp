#pragma once

#include <SFML/Graphics.hpp>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "Hello SFML"
#define POPPINS_PATH "Resources/Poppins.ttf"

using namespace sf;

void LoadFont();

void setText(Text& txt, const std::string& str);

void checkButton();

void draw(RenderWindow& window);
