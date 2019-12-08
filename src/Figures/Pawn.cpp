#include "../../headers/Figures/Pawn.hpp"

Pawn::Pawn(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Pawn::process(sf::RenderWindow & window)
{
    isPieceTouched();
}
