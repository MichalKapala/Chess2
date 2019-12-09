#include "../Piece.hpp"

class Rook: public Piece
{
public:
    int counted_move;
    int possible_moves;

    Rook(Board*, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};


