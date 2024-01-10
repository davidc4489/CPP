#include "Button.hpp"

ButtonFactory::ButtonFactory(float x, float y, float width, float height, const std::string& text, Font& font)
        : shape(sf::Vector2f(width, height)), label(text, font)
        {
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Green);

        label.setFont(font);
        label.setCharacterSize(20);
        label.setFillColor(sf::Color::White);
        label.setString(text);

        // Centrer le texte dans le bouton
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                        textBounds.top + textBounds.height / 2.0f);
        label.setPosition(x + width / 2.0f, y + height / 2.0f);
    }

bool ButtonFactory::isMouseOver(const sf::Vector2i& mousePos) {
    return shape.getGlobalBounds().contains(sf::Vector2f(mousePos));
}

sf::RectangleShape ButtonFactory::getShape(){
    return shape;
}

sf::Text ButtonFactory::getLabel(){
    return label;
}
