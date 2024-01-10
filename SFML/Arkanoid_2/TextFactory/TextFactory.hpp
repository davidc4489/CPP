#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class TextFactory{
public:
    TextFactory() = default;
    Text createText(std::string text, Font& font, Color color, int fontSize, Vector2f position);
};


