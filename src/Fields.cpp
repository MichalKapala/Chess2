#include "../headers/Fields.hpp"


Field::Field(int width, int height, int number)
            : width(width), height(height), number(number)
            {
                holded_piece = -1;
                setPosVector();
                setField();
                setColor();
                setCoordinates();
            }

void Field::setField()
{
    setPosition(position.x, position.y);
    setSize(sf::Vector2f(width, height));

}

void Field::setColor()
{
    if(((position.x/width)%2==0 && (position.y/height)%2==0) ||
        (position.x/width)%2==1 && (position.y/height)%2==1)
        setFillColor(WHITE);
    else
        setFillColor(BLACK);

}

void Field::setPosVector()
{
    position = sf::Vector2i(width*(number%8),height*(number/8));

}

void Field::setCoordinates()
{
   coordinates = parser.getCoordinatesParser(position.x, position.y, width, height);
}
