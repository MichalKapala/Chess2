#include "headers/MainApp.hpp"

int main()
{
    MainApp app;
    sf::RenderWindow window(sf::VideoMode(480, 480), "Chess!");
    app.run(window);
}
