#include "../Piece.hpp"
#include "../Check.hpp"

class King: public Piece
{
public:
    bool is_checked;
    int possible_moves;
    int counted_move;
    std::vector <std::string> possible_moves_vector;

    King(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);
    void calculateMoves();
    void moveKing(sf::RenderWindow &);
    void moveValidation();
    void filterMove();
    void capturePiece(int);
    void addPossibleMove(int, std::string);
};

