#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class EventChecker{
public:
    struct Button { 
        bool right;
        bool left;
        bool escape;
        bool space;
        bool spacer;
    };
    Button button;

public:
    EventChecker();
    EventChecker::Button getButton() const;
    void eventChecker(Event event, RenderWindow& window);
};