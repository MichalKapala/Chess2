#include "../headers/Parser.hpp"

Parser::Parser()
{
    kinds["rook"] = 0;
    kinds["knight"] = 1;
    kinds["bishop"] = 2;
    kinds["queen"] = 3;
    kinds["king"] = 4;
    kinds["pawn"] = 5;
}

sf::Vector2f Parser::getPositionParser(std::string field, int width, int height)
{
    int y_parsed = (8 - (int)(field[1] -'0')) * height;
    int x_parsed = (int(field[0]) - 97) * width;

    return sf::Vector2f(x_parsed, y_parsed);
}

int Parser::kindParser(std::string kind)
{
    int base = 0;
    std::string temporary;
    for(int i=1; i<kind.size(); i++) temporary += kind[i];
    if(kind[0] == 'B') base = 6;

    return base + kinds[temporary];
}

std::string Parser::getCoordinatesParser(int x, int y, int width, int height)
{
    std::string return_string;
    char y_parsed, x_parsed;
    x_parsed = char((x / width) + 97);
    y_parsed = char((8 - (y / width)) + '0');
    return_string += x_parsed;
    return_string += y_parsed;
    return return_string;
}

int Parser::getFieldNumberParser(std::string coords)
{
    return  ((coords[0]) - 97)  + (8 - (int)(coords[1] - '0')) * 8;
}
