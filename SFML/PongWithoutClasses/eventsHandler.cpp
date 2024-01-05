#include "eventsHandler.hpp"

EventsHandler::EventsHandler(){
    button.up_2 = false;
    button.down_2 = false;
    button.up = false; 
    button.down = false;
    button.escape = false;
}

EventsHandler::Button EventsHandler::getButton() const{
    return button;
}

void EventsHandler::eventHandler(Event event, RenderWindow& window){
    if(event.type == Event::Closed){
        window.close();
    }

    if(event.type == Event::KeyPressed){
        switch (event.key.code){
            case Keyboard::Q:
                button.up = true;
                break;
            case Keyboard::A:
                button.down = true;
                break;
            case Keyboard::Up:
                button.up_2 = true;
                break;
            case Keyboard::Down:
                button.down_2 = true;
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
            case Keyboard::Q:
                button.up = false;
                break;
            case Keyboard::A:
                button.down = false;
                break;
            case Keyboard::Up:
                button.up_2 = false;
                break;
            case Keyboard::Down:
                button.down_2 = false;
                break;
            case Keyboard::Escape:
                button.escape = false;
                break;
            default:
                break;
        }
    }  
}