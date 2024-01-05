#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Drawer {
public:
    Drawer() = default;
    
    template <typename T>
    void draw(T item, sf::RenderWindow& window) const {
        window.draw(item);
    }
};