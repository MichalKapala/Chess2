#include "../headers/Fields.hpp"

Field::Field(int x, int y, int width, int height, int number)
            : x(x), y(y), width(width), height(height), number(number)
            {}

void Field::setField(sf::Color color)
{
    setPosition(x, y);
    setSize(sf::Vector2f(width, height));
    setFillColor(color);

}



