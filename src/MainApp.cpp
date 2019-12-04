#include "../headers/MainApp.hpp"
#include "../headers/Fields.hpp"
#include <iostream>


MainApp::MainApp(){
    window = new sf::RenderWindow(sf::VideoMode(480, 480), "Chess!");
}

void MainApp::run(sf::RenderWindow & window)
{
    Field field(22,0,60,60,0);
    field.setField(sf::Color(250, 250, 0));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(field);
        window.display();
    }
}


