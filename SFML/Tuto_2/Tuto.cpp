#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Tuto.hpp"
#include "EventHandler.hpp"

using namespace sf;

Font font;
Text txt;
CircleShape circle;
RectangleShape rectangle;
CircleShape triangle(80.f, 3);
CircleShape hexagone(80.f,6);
Events playerEvent;                  

int main(){
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), WIN_TITLE, Style::Default, settings);

    window.setVerticalSyncEnabled(true);

    LoadFont();

    txt.setFont(font);
    setText(txt, "Hello World!");            
    txt.setCharacterSize(20);       
    txt.setFillColor(Color::Red);   
    txt.setPosition(100, 100);

    circle.setRadius(10);
    circle.setFillColor(Color(125, 75, 25));
    circle.setPosition(200, 200);
    circle.setOutlineThickness(5);
    circle.setOutlineColor(Color::Black);

    rectangle.setSize(Vector2f(100, 100));
    rectangle.setFillColor(Color(125, 75, 25));
    rectangle.setOutlineThickness(5);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setPosition(300, 300);

    triangle.setFillColor(Color(125, 75, 25));
    triangle.setOutlineThickness(5);
    triangle.setOutlineColor(Color::Black);
    triangle.setPosition(400, 400);

    hexagone.setFillColor(Color(125, 75, 25));
    hexagone.setOutlineThickness(5);
    hexagone.setOutlineColor(Color::Black);
    hexagone.setPosition(500, 500);

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            playerEvent.eventHandler(event, window);
            checkButton();
        }

        window.clear(Color::White);
        draw(window);
        window.display();               
    }
    
    return 0;
}

void LoadFont(){
    if(!font.loadFromFile(POPPINS_PATH)){
        std::cout << "Unable to load font" << std::endl;
    }
}

void setText(Text& txt, const std::string& str){
    txt.setString(str);
}

void checkButton(){
    if(playerEvent.getButton().left == true){
        setText(txt, "Left Button Pressed");
        if(txt.getPosition().x > 10){
            txt.setPosition(txt.getPosition().x - 10, txt.getPosition().y);
        }
        if(circle.getPosition().x > 300){
            circle.setPosition(circle.getPosition().x - 100, circle.getPosition().y);
        }
    }
    else if(playerEvent.getButton().right == true){
        setText(txt, "Right Button Pressed");
        if(txt.getPosition().x < WIN_WIDTH - 50){
            txt.setPosition(txt.getPosition().x + 10, txt.getPosition().y);
        }
        if(circle.getPosition().x < WIN_WIDTH - 300){
            circle.setPosition(circle.getPosition().x + 100, circle.getPosition().y);
        }
    }
    else if(playerEvent.getButton().up == true){
        setText(txt, "Up Button Pressed");
        if(txt.getPosition().y - 10 >= 0){
            txt.setPosition(txt.getPosition().x, txt.getPosition().y - 10);
        }
        if(circle.getPosition().y - 100 >= 0){
            circle.setPosition(circle.getPosition().x, circle.getPosition().y - 100);
        }
    }
    else if(playerEvent.getButton().down == true){
        setText(txt, "Down Button Pressed");
        if(txt.getPosition().y + 10 <= WIN_HEIGHT - 50){
            txt.setPosition(txt.getPosition().x, txt.getPosition().y + 10);
        }
        if(circle.getPosition().y + 100 <= WIN_HEIGHT - 300){
            circle.setPosition(circle.getPosition().x, circle.getPosition().y + 100);
        }
    }
    else if(playerEvent.getButton().attack == true){
        setText(txt, "Attack Button Pressed");
    }
}

void draw(RenderWindow& window){
    window.draw(txt);
    window.draw(circle);
    window.draw(rectangle);
    window.draw(triangle);
    window.draw(hexagone);
}

// Pour la compilation : -lsfml-graphics -lsfml-window -lsfml-system