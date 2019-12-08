#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Piece.hpp"
#include "Figures/King.hpp"
#include "Figures/Pawn.hpp"
#include "Figures/Knight.hpp"
#include "Figures/Bishop.hpp"
#include "Figures/Queen.hpp"
#include "Figures/Rook.hpp"

class MainApp{
public:
    MainApp();
    Board * board;
    King *bKing, *wKing;
    Pawn *bPawn1, *bPawn2, *bPawn3, *bPawn4,
        *bPawn5, *bPawn6, *bPawn7, *bPawn8;
    Pawn *wPawn1, *wPawn2, *wPawn3, *wPawn4,
        *wPawn5, *wPawn6, *wPawn7, *wPawn8;
    Knight *wKnight1, *wKnight2, *bKnight1, *bKnight2;
    Bishop *wBishop1, *wBishop2, *bBishop1, *bBishop2;
    Rook *wRook1, *wRook2, *bRook1, *bRook2;
    Queen *wQueen, *bQueen;

    void drawBoard( sf::RenderWindow &);
    void drawFigures(sf::RenderWindow &);
    void processFigures(sf::RenderWindow &);
    void run(sf::RenderWindow &);

};
