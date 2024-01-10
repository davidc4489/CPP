#include "EventChecker.hpp"

EventChecker::EventChecker(){
    button.right = false;
    button.left = false;
    button.escape = true; 
    button.space = false;
    button.spacer = true;
    button.gameOver = false;
    button.win = false;
    button.play = false;
}

EventChecker::Button EventChecker::getButton() const{
    return button;
};

void EventChecker::eventChecker(Event event, RenderWindow& window, std::vector<ButtonFactory>& buttons){
    if(event.type == Event::Closed){
        window.close();
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        ButtonFactory playButton = buttons[0];
        ButtonFactory quitButton = buttons[1];
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (playButton.isMouseOver(mousePos)) {
                button.play = true;
                button.escape = false;
            }

            if (quitButton.isMouseOver(mousePos)) {
                window.close();
            }
        }
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
                button.space = !(button.space);
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