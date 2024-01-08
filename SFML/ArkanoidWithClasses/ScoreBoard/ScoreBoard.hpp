#pragma once

#include <SFML/Graphics.hpp>

class ScoreBoard
{
public:
    ScoreBoard(sf::Color color, int fontSize, int posX, int posY, sf::Font& font);
    int score;
    void incrementScore(int value);
    void resetScore();
    int getScore();
    sf::Text getStrScore();
    sf::Text strScore;
};