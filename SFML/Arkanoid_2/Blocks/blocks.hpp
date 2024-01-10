#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Blocks{
public:
    Blocks(int rows, int cols, int width, int height, std::vector<Color> colors);
    void draw(RenderWindow& window);
    void erase(long unsigned int index);
    std::vector<RectangleShape>& getBlocks();
    void fillVectorBlocks(int rows, int cols, int width, int height, std::vector<Color> colors);
    int rows;
    int cols;
    int width;
    int height;
    std::vector<Color> colors;

private:
    std::vector<RectangleShape> blocks;
};