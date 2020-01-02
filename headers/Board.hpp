#include <SFML/Graphics.hpp>
#include <vector>
#include "Fields.hpp"

#pragma once

class Board
{
public:
    std::vector <Field> fields;
    int width, height;
    int field_width, field_height;
    std::vector <int> captured_pieces;
    bool move_queue;

    Board(int, int);
    void setBoard();
    void drawBoard();
    void setFieldHoldedPiece(int, std::string);
    void resetFields();
    void addCaptured(int);
};
