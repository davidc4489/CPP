#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class TextFactory{
public:
    TextFactory(std::string text, Font& font, Color color, int fontSize, Vector2f position);
    Text text;
};


