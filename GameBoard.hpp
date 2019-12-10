/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: GameBoard is an object that contains all the spaces 
that will be used during gameplay. Its most important role is in the 
construction of the game board. In addition to the cnstructor, it has 
methods for constructing a string to represent itself with, a method 
for deleting all its dynamically-allocated memory, a method for 
getting a specific space, a method for printing out the key for the 
board, and a method for setting all the Spaces' glare data member to 
false.
*********************************************************************/
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