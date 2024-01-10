#include "TopTen.hpp"

using namespace sf;

TopTen::TopTen(sf::Font font){
    for(int i = 0; i < 10; i++){
        Text text;
        text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(Color::White);
        text.setString("Hello");
        text.setPosition(100, 100 + i * 40);
        topTen.insert(topTen.begin() + i, text);
    }    
}

void TopTen::addToTopTen(int score, std::string name){
    // for(int i = 0; i < 10; i++){
        return;
}