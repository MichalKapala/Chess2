#include <SFML/Graphics.hpp>
#include <iostream>
#include "Parser.hpp"

class Field: public sf::RectangleShape
{
public:
    sf::Color WHITE = sf::Color(250, 250, 150);
    sf::Color BLACK = sf::Color(233, 141, 50);
    int number;
    int width, height;
    Parser parser;
    sf::Vector2i position;
    std::string coordinates;

    Field( int, int, int);
    void setColor();
    void setField();
    void setPosVector();
    void setCoordinates();

};
