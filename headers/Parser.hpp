#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Parser
{
public:
    std::map <std::string, int> kinds;

    Parser();
    sf::Vector2f getPositionParser(std::string, int, int);
    std::string getCoordinatesParser(int, int, int, int);
    int kindParser(std::string);
};
