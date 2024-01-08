#include "EventChecker.hpp"

EventChecker::EventChecker(){
    button.right = false;
    button.left = false;
    button.escape = false; 
    button.space = false;
    button.spacer = true;
}

EventChecker::Button EventChecker::getButton() const{
    return button;
}

void EventChecker::eventChecker(Event event, RenderWindow& window){
    if(event.type == Event::Closed){
        window.close();
    }

    if(event.type == Event::KeyPressed){
        switch (event.key.code){
            case Keyboard::Right:
                button.right = true;
                break;
            case Keyboard::Left:
                button.left = true;
                break;
            case Keyboard::Escape:
                button.escape = true;
                break;
            case Keyboard::Space:
                button.space = true;
                break;
            default:
                break;
        }
    }

    if(event.type == Event::KeyReleased){
        switch (event.key.code){
            case Keyboard::Right:
                button.right = false;
                break;
            case Keyboard::Left:
                button.left = false;
                break;
            case Keyboard::Space:
                // button.space = false;
                button.spacer = true;
                break;
            default:
                break;
        }
    }
}