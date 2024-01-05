#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class EventsHandler{
private:
    struct Button {
        bool up_2; 
        bool down_2; 
        bool up;
        bool down;
        bool escape;
    };
    Button button;

public:
    EventsHandler();
    EventsHandler::Button getButton() const;
    void eventHandler(Event event, RenderWindow& window);
};
