#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include "Space.hpp"
#include "Player.hpp"

class GameBoard
{
private:
    int nRows;
    int nCols;
    Space ***spaces;

public:
    GameBoard();
    void printGameBoard();
    void setCharacter(int, int, Character *);
};

#endif