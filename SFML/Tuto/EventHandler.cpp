#include "EventHandler.hpp"
#include "Tuto.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

void eventHandler(Event event, RenderWindow& window, Text* txt){
    if(event.type == Event::Closed){
        window.close();
    }

    if(Keyboard::isKeyPressed(Keyboard::Escape)){
        window.close();
    }

    if(Mouse::isButtonPressed(Mouse::Left)){
        setText(*txt, "Left");
    }

    if(Mouse::isButtonPressed(Mouse::Right)){
        setText(*txt, "Right");
    }

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        setText(*txt, "Right");
    }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        setText(*txt, "Left");
    }

    if(Keyboard::isKeyPressed(Keyboard::Up)){
        setText(*txt, "Up");
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        setText(*txt, "Down");
    }
}