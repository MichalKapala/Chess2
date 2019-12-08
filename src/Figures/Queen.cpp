#include "../../headers/Figures/Queen.hpp"

Queen::Queen(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Queen::process(sf::RenderWindow & window)
{
    ;
}
