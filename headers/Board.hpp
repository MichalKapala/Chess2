#include <SFML/Graphics.hpp>
#include "Fields.hpp"
#include <vector>

class Board
{
public:
    std::vector <Field> fields;
    int width, height;
    int field_width, field_height;

    Board(int, int);
    void setBoard();
    void drawBoard(sf::RenderWindow & window);
};
