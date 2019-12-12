
#include "../Piece.hpp"

class Pawn: public Piece
{
public:
    int counted_move;
    int possible_moves;
    int color_scalar;
    std::vector <std::string> possible_moves_vector;

    Pawn(Board *,std::string, std::string, int, int, int);

    void process(sf::RenderWindow &);
    void moveValidation();
    void movePawn(sf::RenderWindow &);
    void calculateNextMove();
    void calculateFirstMove();
    void calculateCapture();

};
