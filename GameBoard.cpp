#include "GameBoard.hpp"
#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>

using std::cout;
using std::endl;

GameBoard::GameBoard()
{
    nCols = 3;
    nRows = 4;
    spaces = new Space **[nRows];
    for (int i = 0; i < nRows; ++i)
    {
        spaces[i] = new Space *[nCols];
        for (int j = 0; j < nCols; ++j)
        {
            spaces[i][j] = new Empty();
        }
    }
}

void GameBoard::printGameBoard()
{
    cout << endl;
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            cout << "-----";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceTop();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceMiddle();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "|";
            spaces[i][j]->printSpaceBottom();
            cout << "|";
        }
        cout << endl;
        for (int j = 0; j < nCols; ++j)
        {
            cout << "-----";
        }
        cout << endl;
    }
    cout << endl;
}