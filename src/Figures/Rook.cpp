#include "../../headers/Figures/Rook.hpp"

Rook::Rook(Board * board, std::string field, std::string kind, int id, int width, int height):
            Piece(board, field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Rook::process(sf::RenderWindow & window)
{
    movePiece(window);
    board->setFieldHoldedPiece(id, field);
}
