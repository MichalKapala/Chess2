
#include "../Piece.hpp"

class Pawn: public Piece
{
public:
    int counted_move;
    int possible_moves;
    int color_scalar;

    Pawn(std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};
