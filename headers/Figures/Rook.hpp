#include "../Piece.hpp"

class Rook: public Piece
{
public:
    int counted_move;
    int possible_moves;
    std::vector <std::string> possible_moves_vector;

    Rook(Board*, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
    void calculateMoves();
    void moveValidation();
    void moveRook(sf::RenderWindow &);
    void capturePiece(int);
    bool addPossibleMove(int, std::string);
};


