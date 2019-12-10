/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: enterToContinue contains a function that requests 
that the user press "enter" to continue.
*********************************************************************/

#include "enterToContinue.hpp"
#include <string>
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void enterToContinue()
{
    string temp;
    cout << "Press \"enter\" to continue." << endl;
    //receive the input
    cin.get();
    //cear the input out
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}