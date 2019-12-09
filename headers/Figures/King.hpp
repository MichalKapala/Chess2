#include "../Piece.hpp"

class King: public Piece
{

public:
    bool is_checked;
    int possible_moves;

    King(Board *, std::string, std::string, int, int, int);
    void process(sf::RenderWindow &);

};

