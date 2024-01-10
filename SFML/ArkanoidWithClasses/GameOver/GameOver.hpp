#pragma once

#include <SFML/Graphics.hpp>
#include "../Drawer/Drawer.hpp"

using namespace sf;

class GameOver{
public:
    GameOver() = default;
    void gameOver(RenderWindow& window);
};