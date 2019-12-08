#include "../headers/Piece.hpp"
#include <iostream>

Piece::Piece(std::string field, std::string kind, int id, int width, int height)
{
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
}

std::string Piece::getPath()
{
    return "D:/C/Chess2/img/" + kind + ".png";
}

void Piece::setPiece()
{
    texture.loadFromFile(getPath(), sf::IntRect(0, 0, 60, 60));
    texture.setSmooth(true);
    setTexture(texture);
    setPosition(position);
}

void Piece::drawPiece(sf::RenderWindow & window)
{
    ;
}

void Piece::setPieceColor()
{
    if(kind[0] == 'B') color=1;
    else color = 0;
}

void Piece::setPieceKindNumber()
{
    kind_number = parser.kindParser(kind);
    std::cout<<kind_number<<std::endl;
}

bool Piece::isPieceTouched()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        std::cout<<sf::Mouse::getPosition().x<<std::endl;
    return 0;
}
