#include "ScoreBoard.hpp"

ScoreBoard::ScoreBoard(sf::Color color, int fontSize, int posX, int posY, sf::Font& font)
{
    score = 0;
    strScore.setFont(font);
    strScore.setCharacterSize(fontSize);
    strScore.setFillColor(color);
    strScore.setPosition(posX, posY);
    strScore.setString("0");
}

sf::Text ScoreBoard::getStrScore()
{
    return strScore;
}

void ScoreBoard::incrementScore(int value)
{
    score += value;
    strScore.setString(std::to_string(score));
}

void ScoreBoard::resetScore()
{
    score = 0;
    strScore.setString(std::to_string(0));
}

int ScoreBoard::getScore()
{
    return score;
}