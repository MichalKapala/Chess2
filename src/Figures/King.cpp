#include "../../headers/Figures/King.hpp"

King::King(Board * board, std::string field, std::string kind, int id, int width, int height):
            Piece(board, field, kind, id, width, height)
            {
                is_checked = false;
                possible_moves = 0;
            }

void King::process(sf::RenderWindow & window)
{
    movePiece(window);
    board->setFieldHoldedPiece(id, field);
}
