#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;


class Events{
private:
    struct Button {
        bool left; 
        bool right; 
        bool up;
        bool down;
        bool attack;
        bool escape;
    };
    Button button;
public:
    Events();
    void eventHandler(Event event, RenderWindow& window);
    Events::Button getButton() const;
};
