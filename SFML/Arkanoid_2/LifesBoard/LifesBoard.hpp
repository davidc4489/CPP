#pragma once

#include <SFML/Graphics.hpp>

class LifesBoard
{
public:
    LifesBoard(int lifesNumber, int boardWidth, int boardHeight, sf::Color color, float posX, float posY);
    void kill();

    std::vector<sf::RectangleShape> lifes;
};