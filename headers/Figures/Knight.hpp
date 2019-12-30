#include "../Piece.hpp"

class Knight: public Piece
{
public:
    int counted_move;
    int possible_moves;
    std::vector <std::string> possible_moves_vector;

    Knight(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
    void calculateMoves();
    void moveKnight(sf::RenderWindow &);
    void moveValidation();
    void capturePiece(int);
    void addPossibleMove(int, std::string);
};
