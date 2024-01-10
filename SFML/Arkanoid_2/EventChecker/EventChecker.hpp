#pragma once

#include <SFML/Graphics.hpp>
#include "../Button/Button.hpp"
#include <vector>

using namespace sf;

class EventChecker{
public:
    struct Button { 
        bool right;
        bool left;
        bool escape;
        bool space;
        bool spacer;
        bool gameOver;
        bool win;
        bool play;
    };
    Button button;

public:
    EventChecker();
    EventChecker::Button getButton() const;
    void eventChecker(Event event, RenderWindow& window, std::vector<ButtonFactory>& buttons);
};