#include "../headers/Check.hpp"
#include "../headers/Figures/Queen.hpp"
//?
CheckValidation::CheckValidation(Board board, int current_id)
{
    this->board_instance = new Board(board);
    this->current_id = current_id;
    parser = new Parser();
    setColor();
}

CheckValidation::~CheckValidation()
{
    delete board_instance;
    delete parser;
}

void CheckValidation::setColor()
{
    current_color = current_id / 16;
}

void CheckValidation::simulateCurrentMove(std::string current_pos, std::string move_pos)
{
    board_instance->setFieldHoldedPiece(-1, current_pos);
    board_instance->setFieldHoldedPiece(current_id, move_pos);
}

std::string CheckValidation::getKingPos()
{
    int id_to_find = current_color * 16;
    std::string coords;
    for(int i=0; i<board_instance->fields.size(); i++)
    {
        if(id_to_find == board_instance->fields[i].holded_piece)
        {
            coords = board_instance->fields[i].coordinates;
            break;
        }
    }
    return coords;
}
int CheckValidation::pieceToCalculate(std::string field, int id)
{
    int return_value;
    if(id % 16 == 1) calculateQueenMoves(field, id);
    return 0;
}

void CheckValidation::calculatePossibleMoves()
{
    int holded;
    std::string coords;
    for(int i = 0;i < 64; i++)
    {
        holded = board_instance->fields[i].holded_piece;
        if(holded != -1)
        {
            if(holded / 16 != current_id / 16)
            {
                coords = board_instance->fields[i].coordinates;
                pieceToCalculate(coords, holded);
            }
        }
    }
}

void CheckValidation::calculateQueenMoves(std::string field, int id)
{
    Queen * q = new Queen(board_instance, field, "", id, 60 ,60);
    q->calculateMoves();
    for(int i=0; i<q->possible_moves_vector.size(); i++)
    {
        moves.push_back(q->possible_moves_vector[i]);

    }
}

bool CheckValidation::validateMove(std::string current_pos, std::string move_pos)
{
    bool isChecked=false;
    std::string king_pos = getKingPos();
    simulateCurrentMove(current_pos, move_pos);
    calculatePossibleMoves();

    for(int i =0;i<moves.size();i++)
    {
       if(king_pos == moves[i])
        {
            isChecked = true;
            break;
        }
    }

    return isChecked;
}


