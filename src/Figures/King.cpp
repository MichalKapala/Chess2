#include "../../headers/Figures/King.hpp"

King::King(Board * board, std::string field, std::string kind, int id, int width, int height):
            Piece(board, field, kind, id, width, height)
            {
                is_checked = false;
                possible_moves = 0;
                counted_move = 0;
                board->setFieldHoldedPiece(id, field);
            }

void King::process(sf::RenderWindow & window)
{
    moveKing(window);
    deactivation();
}

void King::addPossibleMove(int temp_holded_piece, std::string temp_coords)
{
    if(temp_holded_piece == -1)
        {
            possible_moves_vector.push_back(temp_coords);
        }else{
            if(temp_holded_piece / 16 != id / 16)
                possible_moves_vector.push_back(temp_coords);
        }
}

void King::calculateMoves()
{
    int temp_x = position.x ;
    int temp_y = position.y ;
    int temp_holded_piece;
    std::string temp_coords;
    sf::Vector2i pom_tab[8] = {sf::Vector2i(width, 0), sf::Vector2i(0, height),
                               sf::Vector2i(0, -height), sf::Vector2i(-width, 0),
                               sf::Vector2i(width, -height), sf::Vector2i(-width, height),
                               sf::Vector2i(width, height), sf::Vector2i(-width, -height), };

    for(int i=0; i<8; i++)
    {
        temp_x += pom_tab[i].x;
        temp_y += pom_tab[i].y;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        addPossibleMove(temp_holded_piece, temp_coords);
        resetTempPos(temp_x, temp_y);
    }

}

void King::filterMove()
{
    bool value;
    std::vector <std::string> pom_vector;
    for(int i=0;i<possible_moves_vector.size();i++)
    {
        CheckValidation * valid = new CheckValidation(*board, id);
        value = valid->validateMove(field, possible_moves_vector[i]);
        if(!value)
        {
            pom_vector.push_back(possible_moves_vector[i]);
        }
        delete valid;
    }
    possible_moves_vector.clear();
    possible_moves_vector = pom_vector;
}

void King::moveValidation()
{
    bool found_vector = false;

    calculateMoves();
    filterMove();
    for(int i=0; i < possible_moves_vector.size(); i++)
    {

        if(parser.getCoordinatesParser(moved_position.x, moved_position.y, width, height) == possible_moves_vector[i])
        {
            board->setFieldHoldedPiece(-1, field);
            position = moved_position;
            setCoordinates();
            capturePiece(board->fields[parser.getFieldNumberParser(field)].holded_piece);
            board->setFieldHoldedPiece(id, field);
            found_vector = true;
            counted_move ++;
            board->move_queue = abs((id / 16) - 1);
            break;
        }
    }
    if(!found_vector) moved_position = position;

    setPosition(position);
    possible_moves_vector.clear();

}

void King::capturePiece(int captured_id)
{
    if(captured_id != -1 && captured_id / 16 != id/16)
        board->addCaptured(captured_id);
}

void King::moveKing(sf::RenderWindow & window)
{
    if(isPieceTouchedOnPosition(window) && check_id() && board->move_queue == id /  16)
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
