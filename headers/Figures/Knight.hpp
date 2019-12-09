#include "../Piece.hpp"

class Knight: public Piece
{
public:
    int counted_move;
    int possible_moves;

    Knight(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};
