#include "../../headers/Figures/Queen.hpp"

Queen::Queen(Board * board, std::string field, std::string kind, int id, int width, int height):
            Piece(board, field, kind, id, width, height)
            {
                counted_move = 0;
                board->setFieldHoldedPiece(id, field);
            }

void Queen::process(sf::RenderWindow & window)
{
    moveQueen(window);
    deactivation();
}

bool Queen::addPossibleMove(int temp_holded_piece, std::string temp_coords)
{
    if(temp_holded_piece == -1)
        {
            possible_moves_vector.push_back(temp_coords);
        }else{
            if(temp_holded_piece / 16 != id / 16)
                possible_moves_vector.push_back(temp_coords);
        return 0;

        }
    return 1;
}

void Queen::calculateMoves()
{
    int temp_x = position.x ;
    int temp_y = position.y ;
    int temp_holded_piece;
    std::string temp_coords;

    while(temp_x < board->width - width&& temp_y < board->height - height)
    {
        temp_x += width;
        temp_y += height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;
    }

    resetTempPos(temp_x, temp_y);

    while(temp_x < board->width - width && temp_y >= height)
    {
        temp_x += width;
        temp_y -= height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }

    resetTempPos(temp_x, temp_y);

    while(temp_x >= width && temp_y < board->height - height)
    {
        temp_x -= width;
        temp_y += height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }

    resetTempPos(temp_x, temp_y);

    while(temp_x >= width && temp_y >= height)
    {
        temp_x -= width;
        temp_y -= height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;
    }
    resetTempPos(temp_x, temp_y);

     while(temp_x< board->width - width)
    {
        temp_x += width;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }

    resetTempPos(temp_x, temp_y);

    while(width <= temp_x)
    {
        temp_x-=width;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }

    resetTempPos(temp_x, temp_y);

    while(temp_y < board->height - height)
    {
        temp_y += height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }

    resetTempPos(temp_x, temp_y);

    while(0 <= temp_y - height)
    {
        temp_y-=height;
        temp_coords = parser.getCoordinatesParser(temp_x, temp_y, width, height);
        temp_holded_piece = board->fields[parser.getFieldNumberParser(temp_coords)].holded_piece;
        if (!addPossibleMove(temp_holded_piece, temp_coords)) break;

    }
}

void Queen::filterMove()
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

void Queen::moveValidation()
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
            board->move_queue = abs((id / 16) - 1);
            found_vector = true;
            counted_move ++;
            break;
        }
    }
    if(!found_vector) moved_position = position;

    setPosition(position);
    possible_moves_vector.clear();
}

void Queen::capturePiece(int captured_id)
{
    if(captured_id != -1 && captured_id / 16 != id/16)
        board->addCaptured(captured_id);
}

void Queen::moveQueen(sf::RenderWindow & window)
{
    if(isPieceTouchedOnPosition(window) && check_id() && board->move_queue == id / 16)
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

