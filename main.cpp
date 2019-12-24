#include "headers/MainApp.hpp"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 480), "Chess!");
    sf::Sprite sprite;
    sprite.setPosition(sf::Vector2f(500, 500));

    MainApp app;
    app.run(window);

}
