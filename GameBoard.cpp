#include "GameBoard.hpp"
#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
#include "Player.hpp"
#include "Gate.hpp"
#include "Fence.hpp"
#include "Gravestone.hpp"
#include "Key.hpp"

using std::cout;
using std::endl;

GameBoard::GameBoard()
{
    nCols = 14;
    nRows = 7;
    spaces = new Space **[nRows];

    //initialize spaces
    for (int i = 0; i < nRows; ++i)
    {
        spaces[i] = new Space *[nCols];
        for (int j = 0; j < nCols; ++j)
        {
            //Create the fence and gate
            if (i == 0)
            {
                if (j == 7)
                {
                    spaces[i][j] = new Gate();
                }
                else
                {
                    spaces[i][j] = new Fence();
                }
            }
            //Place gravestones
            else if (i == 1 && j == 2)
            {
                Gravestone *grave = new Gravestone();
                grave->setEngraving("\"Shannon Clark\n1897 - 1950\nOne of these things is not like the others.\"");
                spaces[i][j] = grave;
            }
            else if (i == 5 && j == 3)
            {
                Gravestone *grave = new Gravestone();
                grave->setEngraving("\"Oscar Baxter\n1937 - 1999\nAll dressed up with nowhere to go.\"");
                spaces[i][j] = grave;
            }
            else if (i == 5 && j == 8)
            {
                Gravestone *grave = new Gravestone();
                grave->setEngraving("\"Toby Blankenship\n1921 - 1943\n He called Oliver Murphy a liar.\"");
                spaces[i][j] = grave;
            }
            else if (i == 1 && j == 9)
            {
                Gravestone *grave = new Gravestone();
                grave->setEngraving("\"Oliver Murphy\n1900 - 1969\nThere's an imposter among us ghosts.\"");
                spaces[i][j] = grave;
            }
            //This one will have the key
            else if (i == 6 && j == 8)
            {
                Gravestone *grave = new Gravestone();
                grave->setEngraving("\"JOE'S HALLOWEEN PRACTICAL PROP SHOP\"");
                spaces[i][j] = grave;
            }

            //Fill in every other square
            else
            {
                spaces[i][j] = new Empty();
            }
        }
    }

    //set spaces' pointers
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            spaces[i][j]->setRowCol(i, j);
            //top row
            if (i - 1 < 0)
            {
                spaces[i][j]->setTop(0);
                spaces[i][j]->setBottom(spaces[i + 1][j]);
            }
            //bottom row
            else if (i + 1 >= nRows)
            {
                spaces[i][j]->setBottom(0);
                spaces[i][j]->setTop(spaces[i - 1][j]);
            }
            //somewhere in the middle
            else
            {
                spaces[i][j]->setTop(spaces[i - 1][j]);
                spaces[i][j]->setBottom(spaces[i + 1][j]);
            }

            //left column
            if (j - 1 < 0)
            {
                spaces[i][j]->setLeft(0);
                spaces[i][j]->setRight(spaces[i][j + 1]);
            }
            //right column
            else if (j + 1 >= nCols)
            {
                spaces[i][j]->setRight(0);
                spaces[i][j]->setLeft(spaces[i][j - 1]);
            }
            //somewhere in the middle
            else
            {
                spaces[i][j]->setLeft(spaces[i][j - 1]);
                spaces[i][j]->setRight(spaces[i][j + 1]);
            }
        }
    }
}

string GameBoard::printGameBoard()
{
    string boardVis = "";
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "-----";
        }
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "|";
            boardVis += spaces[i][j]->printSpaceTop();
            boardVis += "|";
        };
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "|";
            boardVis += spaces[i][j]->printSpaceMiddle();
            boardVis += "|";
        }
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "|";
            boardVis += spaces[i][j]->printSpaceBottom();
            boardVis += "|";
        }
        boardVis += "\n";
        for (int j = 0; j < nCols; ++j)
        {
            boardVis += "-----";
        }
        boardVis += "\n";
    }
    boardVis += "\n";
    return boardVis;
}

void GameBoard::deleteGameBoard()
{
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            delete spaces[i][j];
        }
        delete[] spaces[i];
    }
    delete[] spaces;
}

Space *GameBoard::getSpaceAt(int row, int col)
{
    return spaces[row][col];
}

void GameBoard::printKey()
{
    cout << endl
         << endl;
    cout << "|, --";
    cout << "        ";
    cout << "Space boundaries" << endl;
    cout << "X";
    cout << "            ";
    cout << "Player location" << endl;
    cout << "---";
    cout << "          ";
    cout << "Fence" << endl;
    cout << "===";
    cout << "          ";
    cout << "Gate" << endl;
    cout << "t";
    cout << "            ";
    cout << "Gravestone";
    cout << "#";
    cout << "            ";
    cout << "Item";
    cout << "G";
    cout << "            ";
    cout << "Ghost";
    cout << "g";
    cout << "            ";
    cout << "???";
    cout << endl
         << endl;
}

int GameBoard::getNRows()
{
    return nRows;
}

int GameBoard::getNCols()
{
    return nCols;
}

void GameBoard::resetGlares()
{
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            spaces[i][j]->setGlare(false);
        }
    }
}