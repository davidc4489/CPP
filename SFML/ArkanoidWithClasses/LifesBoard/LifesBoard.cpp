#include "LifesBoard.hpp"
LifesBoard::LifesBoard(int lifesNumber, int boardWidth, int boardHeight, sf::Color color, float posX, float posY)
{
    for (int i = 0; i < lifesNumber - 1; i++)
    {
        sf::RectangleShape life;
        life.setSize(sf::Vector2f(boardWidth, boardHeight));
        life.setPosition(sf::Vector2f((i * (1.5 * boardWidth)) + posX, posY));
        life.setFillColor(color);
        lifes.push_back(life);
    }
}
void LifesBoard::kill()
{
    lifes.pop_back();
}