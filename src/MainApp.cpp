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
       if(bKing->isPieceActive()) window.draw(*bKing);
        if(bQueen->isPieceActive()) window.draw(*bQueen);
        if(bKnight1->isPieceActive()) window.draw(*bKnight1);
        if(bKnight2->isPieceActive()) window.draw(*bKnight2);
        if(bBishop1->isPieceActive()) window.draw(*bBishop1);
        if(bBishop2->isPieceActive()) window.draw(*bBishop2);
        if(bRook1->isPieceActive()) window.draw(*bRook1);
        if(bRook2->isPieceActive()) window.draw(*bRook2);
        if(bPawn1->isPieceActive()) window.draw(*bPawn1);
        if(bPawn2->isPieceActive()) window.draw(*bPawn2);
        if(bPawn3->isPieceActive()) window.draw(*bPawn3);
        if(bPawn4->isPieceActive()) window.draw(*bPawn4);
        if(bPawn5->isPieceActive()) window.draw(*bPawn5);
        if(bPawn6->isPieceActive()) window.draw(*bPawn6);
        if(bPawn7->isPieceActive()) window.draw(*bPawn7);
        if(bPawn8->isPieceActive()) window.draw(*bPawn8);
        if(wKing->isPieceActive()) window.draw(*wKing);
        if(wQueen->isPieceActive()) window.draw(*wQueen);
        if(wKnight1->isPieceActive()) window.draw(*wKnight1);
        if(wKnight2->isPieceActive()) window.draw(*wKnight2);
        if(wBishop1->isPieceActive()) window.draw(*wBishop1);
        if(wBishop2->isPieceActive()) window.draw(*wBishop2);
        if(wRook1->isPieceActive()) window.draw(*wRook1);
        if(wRook2->isPieceActive()) window.draw(*wRook2);
        if(wPawn1->isPieceActive()) window.draw(*wPawn1);
        if(wPawn2->isPieceActive()) window.draw(*wPawn2);
        if(wPawn3->isPieceActive()) window.draw(*wPawn3);
        if(wPawn4->isPieceActive()) window.draw(*wPawn4);
        if(wPawn5->isPieceActive()) window.draw(*wPawn5);
        if(wPawn6->isPieceActive()) window.draw(*wPawn6);
        if(wPawn7->isPieceActive()) window.draw(*wPawn7);
        if(wPawn8->isPieceActive()) window.draw(*wPawn8);
}

void MainApp::processFigures(sf::RenderWindow & window)
{

    if(bKing->isPieceActive()) bKing->process(window);
    if(bQueen->isPieceActive()) bQueen->process(window);
    if(bBishop1->isPieceActive()) bBishop1->process(window);
    if(bBishop2->isPieceActive()) bBishop2->process(window);
    if(bKnight1->isPieceActive()) bKnight1->process(window);
    if(bKnight2->isPieceActive()) bKnight2->process(window);
    if(bRook1->isPieceActive()) bRook1->process(window);
    if(bRook2->isPieceActive()) bRook2->process(window);
    if(bPawn1->isPieceActive())  bPawn1->process(window);
    if(bPawn2->isPieceActive()) bPawn2->process(window);
    if(bPawn3->isPieceActive())  bPawn3->process(window);
    if(bPawn4->isPieceActive()) bPawn4->process(window);
    if(bPawn5->isPieceActive()) bPawn5->process(window);
    if(bPawn6->isPieceActive()) bPawn6->process(window);
    if(bPawn7->isPieceActive())  bPawn7->process(window);
    if(bPawn8->isPieceActive()) bPawn8->process(window);
    if(wKing->isPieceActive()) wKing->process(window);
    if(wQueen->isPieceActive()) wQueen->process(window);
    if(wBishop1->isPieceActive()) wBishop1->process(window);
    if(wBishop2->isPieceActive()) wBishop2->process(window);
    if(wKnight1->isPieceActive()) wKnight1->process(window);
    if(wKnight2->isPieceActive()) wKnight2->process(window);
    if(wRook1->isPieceActive()) wRook1->process(window);
    if(wRook2->isPieceActive()) wRook2->process(window);
    if(wPawn1->isPieceActive())  wPawn1->process(window);
    if(wPawn2->isPieceActive()) wPawn2->process(window);
    if(wPawn3->isPieceActive())  wPawn3->process(window);
    if(wPawn4->isPieceActive()) wPawn4->process(window);
    if(wPawn5->isPieceActive()) wPawn5->process(window);
    if(wPawn6->isPieceActive()) wPawn6->process(window);
    if(wPawn7->isPieceActive())  wPawn7->process(window);
    if(wPawn8->isPieceActive()) wPawn8->process(window);

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


