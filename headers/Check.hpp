#include "Board.hpp"
#include "Parser.hpp"
#pragma once

class CheckValidation
{
public:
    Board * board_instance;
    Parser * parser;
    std::vector <std::string> moves;
    bool current_color;
    int current_id;

    CheckValidation(Board, int);
    ~CheckValidation();
    void setColor();
    void simulateCurrentMove(std::string, std::string);
    void calculatePossibleMoves();
    void calculateQueenMoves(std::string, int);
    void calculateKingMoves(std::string, int);
    void calculateBishopMoves(std::string, int);
    void calculateKnightMoves(std::string, int);
    void calculateRookMoves(std::string, int);
    void calculatePawnMoves(std::string, int);
    std::string getKingPos();
    int pieceToCalculate(std::string, int);
    bool validateMove(std::string, std::string);
};
