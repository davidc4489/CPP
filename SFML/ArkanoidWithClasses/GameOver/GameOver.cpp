#include "GameOver.hpp"

void GameOver::gameOver(RenderWindow& window){
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 5) {};
    window.close();
}