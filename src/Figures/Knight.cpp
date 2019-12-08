#include "../../headers/Figures/Knight.hpp"

Knight::Knight(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                counted_move = 0;
            }

void Knight::process(sf::RenderWindow & window)
{
    ;
}
