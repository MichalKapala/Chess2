#include "../Piece.hpp"

class Bishop: public Piece
{
public:
    int counted_move;
    int possible_moves;
    std::vector <std::string> possible_moves_vector;

    Bishop(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
    void calculateMoves();
    void moveBishop(sf::RenderWindow &);
    void moveValidation();
};

