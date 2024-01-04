#include "EventHandler.hpp"
#include "Tuto.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

Events::Events(){
    button.left = false;
    button.right = false;
    button.up = false; 
    button.down = false;
    button.attack = false; 
    button.escape = false;
}

void Events::eventHandler(Event event, RenderWindow& window){
    if(event.type == Event::Closed){
        window.close();
    }

    if(event.type == Event::KeyPressed){
        switch (event.key.code){
            case Keyboard::Left:
                button.left = true;
                break;
            case Keyboard::Right:
                button.right = true;
                break;
            case Keyboard::Up:
                button.up = true;
                break;
            case Keyboard::Down:
                button.down = true;
                break;
            case Keyboard::Escape:
                button.escape = true;
                break;
            default:
                break;
        }
    }

    if(event.type == Event::KeyReleased){
        switch (event.key.code){
            case Keyboard::Left:
                button.left = false;
                break;
            case Keyboard::Right:
                button.right = false;
                break;
            case Keyboard::Up:
                button.up = false;
                break;
            case Keyboard::Down:
                button.down = false;
                break;
            case Keyboard::Escape:
                button.escape = false;
                break;
            default:
                break;
        }
    }

    if(event.type == Event::MouseButtonPressed){
        if(event.mouseButton.button == Mouse::Left){
            button.attack = true;
        }
    }

    if(event.type == Event::MouseButtonReleased){
        if (event.mouseButton.button == Mouse::Left){
            button.attack = false;
        }
    }     
}

Events::Button Events::getButton() const{
    return button;
}
