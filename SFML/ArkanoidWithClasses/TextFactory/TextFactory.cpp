#include "TextFactory.hpp"
TextFactory::TextFactory(std::string str, Font& font, Color color, int fontSize, Vector2f position){
    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setPosition(position);
    text.setFillColor(color);
}