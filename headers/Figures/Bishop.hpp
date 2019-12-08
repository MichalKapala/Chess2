#include "../Piece.hpp"

class Bishop: public Piece
{
public:
    int counted_move;
    int possible_moves;

    Bishop(std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
};
