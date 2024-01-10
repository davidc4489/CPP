#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class TopTen{
public:
    TopTen(sf::Font font);
    std::vector<Text> topTen;
    void addToTopTen(int score, std::string name);
};