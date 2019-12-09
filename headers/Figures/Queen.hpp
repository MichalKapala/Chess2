#include "../Piece.hpp"

class Queen: public Piece
{
public:
    int counted_move;
    int possible_moves;

    Queen(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};

