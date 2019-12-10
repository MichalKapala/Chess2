#include "../headers/Piece.hpp"
#include <iostream>

int Piece::moved_id = -1;

Piece::Piece(Board * board, std::string field, std::string kind, int id, int width, int height)
{
    this->board = board;
    this->field = field;
    this->kind = kind;
    this->id = id;
    this->width = width;
    this->height = height;
    setPiecePosition();
    setPieceKindNumber();
    setPieceColor();
    setPiece();
}

void Piece::setPiecePosition()
{
    position = parser.getPositionParser(field, width, height);
    moved_position = position;
}

std::string Piece::getPath()
{
    return "img/" + kind + ".png";
}

void Piece::setPiece()
{
    texture.loadFromFile(getPath(), sf::IntRect(0, 0, 60, 60));
    texture.setSmooth(true);
    setTexture(texture);
    setPosition(position);
}

void Piece::setPieceColor()
{
    if(kind[0] == 'B') color = -1;
    else color = 1;
}

void Piece::setPieceKindNumber()
{
    kind_number = parser.kindParser(kind);
}

bool Piece::isPieceTouchedOnPosition(sf::RenderWindow & window)
{
    if( moved_position.x <= sf::Mouse::getPosition(window).x &&
       sf::Mouse::getPosition(window).x < moved_position.x + width &&
       moved_position.y <= sf::Mouse::getPosition(window).y &&
       sf::Mouse::getPosition(window).y < moved_position.y + height)
        return 1;
    return 0;
}


bool Piece::check_id()
{
    return (moved_id == -1 || moved_id == id);
}

void Piece::movePiece(sf::RenderWindow & window)
{

    if(isPieceTouchedOnPosition(window) && check_id())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            moved_id = id;
            moved_position.x = sf::Mouse::getPosition(window).x - (width / 2);
            moved_position.y = sf::Mouse::getPosition(window).y - (height / 2);
            setPosition(moved_position);
        }
        else{
            moved_id = -1;
            center();
    }
    }

}

void Piece::center()
{
    int y_field, x_field;

    x_field = moved_position.x / width;
    y_field = moved_position.y / height;

    if((int)moved_position.x % width > width / 2)
        moved_position.x = (x_field + 1) * width;
    else
        moved_position.x = x_field * width;

    if((int)moved_position.y % height > height / 2)
        moved_position.y = (y_field + 1)  * height;
    else
        moved_position.y = y_field * height;

}

void Piece::setCoordinates()
{
    field = parser.getCoordinatesParser(position.x, position.y, width, height);
    std::cout<<field<<" "<<board->fields[parser.getFieldNumberParser(field)].coordinates<<std::endl;
}

void Piece::changePosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

