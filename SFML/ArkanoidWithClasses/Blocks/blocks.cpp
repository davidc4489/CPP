#include "blocks.hpp"

Blocks::Blocks(int rows, int cols, int width, int height, std::vector<Color> colors)
{
    int initX = 100;
    int initY = 70;
    Color color = colors[0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            blocks.push_back(RectangleShape(Vector2f(width, height)));
            blocks[i * cols + j].setFillColor(color);
            blocks[i * cols + j].setPosition(Vector2f(initX, initY));
            blocks[i * cols + j].setOutlineThickness(1);
            blocks[i * cols + j].setOutlineColor(Color::White);
            initX += width;
            if(j == cols - 1){
                initX = 100;
                initY += height;
            }
        }
        color = colors[(i + 1) % colors.size()];
    }
}
void Blocks::draw(RenderWindow& window){
    for(long unsigned int i = 0; i < blocks.size(); i++){
        window.draw(blocks[i]);
    }
}

void Blocks::erase(long unsigned int index){
    if(blocks.size() > index)
    blocks.erase(blocks.begin() + index);
}

std::vector<RectangleShape>& Blocks::getBlocks(){
    return blocks;
}
