#include "../../headers/Figures/Rook.hpp"

Rook::Rook(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Rook::process(sf::RenderWindow & window)
{
    ;
}
