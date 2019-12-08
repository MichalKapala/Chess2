#include "../Piece.hpp"

class Rook: public Piece
{
public:
    int counted_move;
    int possible_moves;

    Rook(std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};


