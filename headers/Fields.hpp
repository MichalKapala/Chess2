#include <SFML/Graphics.hpp>
#include "DrawableObject.hpp"
class Field: public sf::RectangleShape
{
public:
    int number;
    int x,y;
    int width, height;

    Field(int, int, int, int, int);
    void setField(sf::Color);

};
