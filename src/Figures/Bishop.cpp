#include "../../headers/Figures/Bishop.hpp"

Bishop::Bishop(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Bishop::process(sf::RenderWindow & window)
{
    ;
}
