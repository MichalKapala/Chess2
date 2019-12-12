#include "../../headers/Figures/Pawn.hpp"

Pawn::Pawn(Board * board, std::string field, std::string kind, int id, int width, int height):
            Piece(board, field, kind, id, width, height)
            {
                counted_move = 0;
                board->setFieldHoldedPiece(id, field);
            }

void Pawn::process(sf::RenderWindow & window)
{
    movePawn(window);
}

void Pawn::calculateNextMove()
{
    std::string nextfield;
    nextfield += field[0];
    nextfield += (char)(field[1] + color);
    if(board->fields[parser.getFieldNumberParser(nextfield)].holded_piece == -1)
    {
        possible_moves_vector.push_back(nextfield);
    }


}

void Pawn::calculateFirstMove()
{
    std::string nextfield;
    nextfield += field[0];
    nextfield += (char)(field[1] + 2*color);
    if(board->fields[parser.getFieldNumberParser(nextfield)].holded_piece == -1 &&
       counted_move == 0)
        possible_moves_vector.push_back(nextfield);
}

void Pawn::calculateCapture()
{
    std::string nextfield1;
    std::string nextfield2;
    int holded_piece1;
    int holded_piece2;

    nextfield1 += field[0] - 1;
    nextfield1 += (char)(field[1] + color);
    nextfield2 += field[0] + 1;
    nextfield2 += (char)(field[1] + color);
    holded_piece1 = board->fields[parser.getFieldNumberParser(nextfield1)].holded_piece;
    holded_piece2 = board->fields[parser.getFieldNumberParser(nextfield2)].holded_piece;

    if(holded_piece1 != -1 && holded_piece1 / 16 != id / 16)
        possible_moves_vector.push_back(nextfield1);
    if(holded_piece2 != -1 && holded_piece2 / 16 != id / 16)
        possible_moves_vector.push_back(nextfield2);

}


void Pawn::moveValidation()
{
    bool found_vector = false;

    calculateNextMove();
    calculateFirstMove();
    calculateCapture();

    for(int i=0; i < possible_moves_vector.size(); i++)
    {
        if(parser.getCoordinatesParser(moved_position.x, moved_position.y, width, height) == possible_moves_vector[i])
        {
            board->setFieldHoldedPiece(-1, field);
            position = moved_position;
            setCoordinates();
            board->setFieldHoldedPiece(id, field);
            found_vector = true;
            counted_move ++;
            break;
        }
    }
    if(!found_vector) moved_position = position;
    setPosition(position);
    possible_moves_vector.clear();

}

void Pawn::movePawn(sf::RenderWindow & window)
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
            moveValidation();
        }
    }
}

