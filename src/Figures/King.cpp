#include "../../headers/Figures/King.hpp"

King::King(std::string field, std::string kind, int id, int width, int height):
            Piece(field, kind, id, width, height)
            {
                is_checked = false;
                possible_moves = 0;
            }

void King::process(sf::RenderWindow & window)
{
    ;
}
