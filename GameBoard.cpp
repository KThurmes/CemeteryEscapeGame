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
#include "GameBoard.hpp"
#include "Space.hpp"
#include "Empty.hpp"
#include <iostream>
#include "Player.hpp"
#include "Gate.hpp"
#include "Fence.hpp"
#include "Gravestone.hpp"

using std::cout;
using std::endl;

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: The GameBoard constructor sets up a board with 
different spaces. It does not add any Characters.
*********************************************************************/
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

            //Fill in every other square with an empty tile.
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

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: printGameBoard doesn't actually print anything to the 
console, but returns a string that, when printed to the console, 
represents the game board, sans characters.
*********************************************************************/
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

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: deleteGameBoard frees the game board's memory.
*********************************************************************/
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

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: getSpaceAt returns a pointer to the space that is 
located at row, column.
*********************************************************************/
Space *GameBoard::getSpaceAt(int row, int col)
{
    return spaces[row][col];
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: printKey prints a key to the map
*********************************************************************/
void GameBoard::printKey()
{
    cout << endl
         << endl;
    cout << "|, --";
    cout << "        ";
    cout << "Space boundaries" << endl;
    cout << "x";
    cout << "            ";
    cout << "Player location" << endl;
    cout << "---";
    cout << "          ";
    cout << "Fence" << endl;
    cout << "===";
    cout << "          ";
    cout << "Gate" << endl;
    cout << "n";
    cout << "            ";
    cout << "Gravestone" << endl;
    cout << "#";
    cout << "            ";
    cout << "Item" << endl;
    cout << "G            ";
    cout << "Ghost" << endl;
    cout << "<, ^, >, v   ";
    cout << "Direction indicators" << endl;
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

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: resetGlares goes through all the Spaces in the 
gameBoard and sets all their "glare" bools to false.
*********************************************************************/
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