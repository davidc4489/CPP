#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Tuto.hpp"
#include "EventHandler.hpp"

using namespace sf;

Font font;
Text txt;    // Création du texte

int main(){
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), WIN_TITLE);

/*  L'activation de la synchronisation verticale limitera le nombre d'images affichées au taux de rafraîchissement du moniteur. 
    Cela peut éviter certains artefacts visuels et limiter le framerate à une bonne valeur (mais pas constante sur différents ordinateurs). */
    window.setVerticalSyncEnabled(true);

    LoadFont();                     // Chargement de la police de caractères

    txt.setFont(font);              // Font du texte
    txt.setCharacterSize(20);       // Taille du texte
    txt.setFillColor(Color::Red);   // Couleur du texte
    txt.setPosition(100, 100);      // Position du texte

    sf::Clock clock; // démarre le chrono

/*  pollEvent() :
    Placez l'événement en haut de la file d'attente des événements, le cas échéant, et renvoyez-le.
    Cette fonction n'est pas bloquante : s'il n'y a pas d'événement en attente, elle renverra false et laissera l'événement inchangé. 
    Notez que plusieurs événements peuvent être présents dans la file d'attente des événements, vous devez donc toujours appeler cette fonction en boucle pour vous assurer que vous traitez chaque événement en attente. */
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            eventHandler(event, window, &txt);
        }

        if (clock.getElapsedTime().asSeconds() < 5) {
            setText(txt, "Ready ?");
        }

        if (clock.getElapsedTime().asSeconds() > 5 && clock.getElapsedTime().asSeconds() < 6) {
            setText(txt, "Hello World !");
        }

        window.clear(Color::White);
        window.draw(txt);
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

// Pour la compilation : -lsfml-graphics -lsfml-window -lsfml-system