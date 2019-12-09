#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <string>
#include "Space.hpp"
#include "Player.hpp"
using std::string;

class GameBoard
{
private:
    int nRows;
    int nCols;
    Space ***spaces;

public:
    GameBoard();
    string printGameBoard();
    void deleteGameBoard();
    Space *getSpaceAt(int, int);
    void printKey();
    int getNCols();
    int getNRows();
    void resetGlares();
};

#endif