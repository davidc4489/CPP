#include<SFML/Graphics.hpp>
#include<time.h>
using namespace sf;

int main()
{

    srand(time(0));  // initialise la graine pour la génération de nombres aléatoires basée sur le temps actuel
    RenderWindow window(VideoMode(520, 450), "Pay the Game....!");
    window.setFramerateLimit(60);

    Texture texture1, texture2, texture3, texture4, texture5;
    texture1.loadFromFile("Images/B01.png");
    texture2.loadFromFile("Images/BackG.png");
    texture3.loadFromFile("Images/ball.png");
    texture4.loadFromFile("Images/paddle.png");
    texture5.loadFromFile("Images/B02.png");

    Sprite sBackG(texture2), sBall(texture3), sPaddle(texture4);
    sPaddle.setPosition(300, 440);
    sBall.setPosition(300, 300);

    Sprite block[1000];

    int n = 0;
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j <= 10; j++){
            (n%2 == 0)? block[n].setTexture(texture1): block[n].setTexture(texture5);
            block[n].setPosition(i * 43, j * 20);
            n++;
        }
    }

    float dx = 6, dy = 5;
    float x = 300, y = 300;

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }

        x += dx;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds())){
                block[i].setPosition(-100, 0); dx = -dx;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds())){
                block[i].setPosition(-100, 0); dy = -dy;
            }

        if (x < 0 || x>520)  dx = -dx;
        if (y < 0 || y>450)  dy = -dy;

        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(6, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-6, 0);

        if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);

        sBall.setPosition(x, y);

        window.clear();
        window.draw(sBackG);
        window.draw(sBall);
        window.draw(sPaddle);

        for (int i = 0; i < n; i++){
            window.draw(block[i]);
        }

        window.display();

    }

    return 0;
}