#include <SFML/Graphics.hpp>
#include "Parser.hpp"
#include "Board.hpp"
#pragma once

class Piece: public sf::Sprite
{
public:
    static int moved_id;
    int id;
    int width, height;
    int color, kind_number;
    bool is_active = true;
    std::string kind, field, image_path;
    Parser parser;
    Board * board;

    sf::Vector2f position;
    sf::Vector2f moved_position;
    sf::Texture texture;

    Piece(Board *, std::string, std::string, int, int, int);
    std::string getPath();
    void movePiece(sf::RenderWindow &);
    void setPiece();
    void setPiecePosition();
    void changeActiveStatment();
    void setPieceColor();
    void drawPiece(sf::RenderWindow &);
    void setPieceKindNumber();
    void center();
    void moveInto(std::string);
    void moveInto(sf::Vector2f);
    void changePosition(float, float);
    bool isPieceActive();
    bool isPieceTouchedOnPosition(sf::RenderWindow &);
    bool check_id();

};
