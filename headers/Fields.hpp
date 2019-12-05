#include <SFML/Graphics.hpp>

class Field: public sf::RectangleShape
{
public:
    sf::Color WHITE = sf::Color(250, 250, 150);
    sf::Color BLACK = sf::Color(233, 141, 50);
    int number;
    int width, height;
    sf::Vector2i position;

    Field( int, int, int);
    void setColor();
    void setField();
    void setPosVector();

};
