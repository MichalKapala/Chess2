#include "../headers/Board.hpp"


Board::Board(int width, int height):
            width(width), height(height)
             {
                 field_width = width/8;
                 field_height = height/8;
                 setBoard();
             }

void Board::setBoard()
{
       for(int i=0; i<64; i++)
        fields.push_back(Field(field_width, field_height, i));
}

