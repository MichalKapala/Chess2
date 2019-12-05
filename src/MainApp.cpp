#include "../headers/MainApp.hpp"
#include "../headers/Board.hpp"
#include <iostream>

const int WINDOW_HEIGHT=480;
const int WINDOW_WIDTH=480;

MainApp::MainApp(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chess!");
}

void MainApp::run(sf::RenderWindow & window)
{
    Board board(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        for(int i=0;i<board.fields.size();i++) window.draw(board.fields[i]);
        window.display();
    }
}


