#include "../headers/MainApp.hpp"
#include <iostream>

const int WINDOW_HEIGHT=480;
const int WINDOW_WIDTH=480;


MainApp::MainApp(){
    board = new Board(WINDOW_WIDTH, WINDOW_HEIGHT);
    bKing = new King(board, "e8", "Bking", 16, 60, 60);
    bQueen = new Queen(board, "d8", "BQueen", 17, 60, 60);
    bBishop1 = new Bishop(board, "f8", "Bbishop", 18, 60, 60);
    bBishop2 = new Bishop(board, "c8", "Bbishop", 19, 60, 60);
    bKnight1 = new Knight(board, "g8", "Bknight", 20, 60, 60);
    bKnight2 = new Knight(board, "b8", "Bknight", 21, 60, 60);
    bRook1 = new Rook(board, "h8", "Brook", 22, 60, 60);
    bRook2 = new Rook(board, "a8", "Brook", 23, 60, 60);
    bPawn1 = new Pawn(board, "a7", "Bpawn", 24, 60, 60);
    bPawn2 = new Pawn(board, "b7", "Bpawn", 25, 60, 60),
    bPawn3 = new Pawn(board, "c7", "Bpawn", 26, 60, 60);
    bPawn4 = new Pawn(board, "d7", "Bpawn", 27, 60, 60);
    bPawn5 = new Pawn(board, "e7", "Bpawn", 28, 60, 60);
    bPawn6 = new Pawn(board, "f7", "Bpawn", 29, 60, 60);
    bPawn7 = new Pawn(board, "g7", "Bpawn", 30, 60, 60);
    bPawn8 = new Pawn(board, "h7", "Bpawn", 31, 60, 60);
    wKing = new King(board, "e1", "Wking", 0, 60, 60);
    wQueen = new Queen(board, "d1", "Wqueen", 1, 60, 60);
    wBishop1 = new Bishop(board, "f1", "Wbishop", 2, 60, 60);
    wBishop2 = new Bishop(board, "c1", "Wbishop", 3, 60, 60);
    wKnight1 = new Knight(board, "g1", "Wknight", 4, 60, 60);
    wKnight2 = new Knight(board, "b1", "Wknight", 5, 60, 60);
    wRook1 = new Rook(board, "h1", "Wrook", 6, 60, 60);
    wRook2 = new Rook(board, "a1", "Wrook", 7, 60, 60);
    wPawn1 = new Pawn(board, "a2", "Wpawn", 8, 60, 60);
    wPawn2 = new Pawn(board, "b2", "Wpawn", 9, 60, 60),
    wPawn3 = new Pawn(board, "c2", "Wpawn", 10, 60, 60);
    wPawn4 = new Pawn(board, "d2", "Wpawn", 11, 60, 60);
    wPawn5 = new Pawn(board, "e2", "Wpawn", 12, 60, 60);
    wPawn6 = new Pawn(board, "f2", "Wpawn", 13, 60, 60);
    wPawn7 = new Pawn(board, "g2", "Wpawn", 14, 60, 60);
    wPawn8 = new Pawn(board, "h2", "Wpawn", 15, 60, 60);
}

void MainApp::drawFigures(sf::RenderWindow & window)
{
        window.draw(*bKing);
        window.draw(*bQueen);
        window.draw(*bKnight1);
        window.draw(*bKnight2);
        window.draw(*bBishop1);
        window.draw(*bBishop2);
        window.draw(*bRook1);
        window.draw(*bRook2);
        window.draw(*bPawn1);
        window.draw(*bPawn2);
        window.draw(*bPawn3);
        window.draw(*bPawn4);
        window.draw(*bPawn5);
        window.draw(*bPawn6);
        window.draw(*bPawn7);
        window.draw(*bPawn8);
        window.draw(*bBishop1);
        window.draw(*bBishop2);
        window.draw(*wKing);
        window.draw(*wQueen);
        window.draw(*wKnight1);
        window.draw(*wKnight2);
        window.draw(*wBishop1);
        window.draw(*wBishop2);
        window.draw(*wRook1);
        window.draw(*wRook2);
        window.draw(*wPawn1);
        window.draw(*wPawn2);
        window.draw(*wPawn3);
        window.draw(*wPawn4);
        window.draw(*wPawn5);
        window.draw(*wPawn6);
        window.draw(*wPawn7);
        window.draw(*wPawn8);
}

void MainApp::processFigures(sf::RenderWindow & window)
{

    bKing->process(window);
    bQueen->process(window);
    bBishop1->process(window);
    bBishop2->process(window);
    bKnight1->process(window);
    bKnight2->process(window);
    bRook1->process(window);
    bRook2->process(window);
    bPawn1->process(window);
    bPawn2->process(window);
    bPawn3->process(window);
    bPawn4->process(window);
    bPawn5->process(window);
    bPawn6->process(window);
    bPawn7->process(window);
    bPawn8->process(window);
    wKing->process(window);
    wQueen->process(window);
    wBishop1->process(window);
    wBishop2->process(window);
    wKnight1->process(window);
    wKnight2->process(window);
    wRook1->process(window);
    wRook2->process(window);
    wPawn1->process(window);
    wPawn2->process(window);
    wPawn3->process(window);
    wPawn4->process(window);
    wPawn5->process(window);
    wPawn6->process(window);
    wPawn7->process(window);
    wPawn8->process(window);

}

void MainApp::drawBoard(sf::RenderWindow & window)
{
    for(int i=0;i<board->fields.size();i++) window.draw(board->fields[i]);
}

void MainApp::run(sf::RenderWindow & window)
{

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        drawBoard( window);
        drawFigures(window);
        processFigures(window);
        window.display();
    }

}


