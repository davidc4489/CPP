#include "TextFactory.hpp"
Text TextFactory::createText(std::string str, Font& font, Color color, int fontSize, Vector2f position){
    Text newText;
    newText.setString(str);
    newText.setFont(font);
    newText.setCharacterSize(fontSize);
    newText.setPosition(position);
    newText.setFillColor(color);
    return newText;
}