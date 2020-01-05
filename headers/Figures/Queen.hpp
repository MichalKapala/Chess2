#include "../Piece.hpp"
#include "../Check.hpp"

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
    void filterMove();
    void capturePiece(int);
    bool addPossibleMove(int, std::string);
};

