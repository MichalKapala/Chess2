#include "../Piece.hpp"

class Queen: public Piece
{
public:
    int counted_move;
    int possible_moves;
    std::vector <std::string> possible_moves_vector;

    Queen(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
    void calculateMoves();
    void moveQueen(sf::RenderWindow &);
    void moveValidation();
    bool addPossibleMove(int, std::string);
};

