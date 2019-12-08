#include <SFML/Graphics.hpp>
#include "Parser.hpp"
#pragma once

class Piece: public sf::Sprite
{
public:
    int id;
    int width, height;
    int color, kind_number;
    bool is_active = true;
    std::string kind, field, image_path;
    Parser parser;
    sf::Vector2f position;
    sf::Texture texture;

    Piece(std::string, std::string, int, int, int);
    std::string getPath();
    void setPiece();
    void setPiecePosition();
    void changeActiveStatment();
    void setPieceColor();
    void drawPiece(sf::RenderWindow &);
    void setPieceKindNumber();
    bool isPieceActive();
    bool isPieceTouched();

};
