#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class ButtonFactory {
public:
    ButtonFactory(float x, float y, float width, float height, const std::string& text, Font& font);
    bool isMouseOver(const sf::Vector2i& mousePos);
    sf::RectangleShape getShape();
    sf::Text getLabel();

private:
    sf::RectangleShape shape;
    sf::Text label;
    sf::Font font;
};
