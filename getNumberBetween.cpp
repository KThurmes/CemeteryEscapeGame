/********************************************************************* 
** Author: Katheen Thurmes
** Date: 19 Oct., 2019
** Description: getNumberBetween()  is a 
function that will ask the user to select a number between "low" and 
"high" (inclusive).  It calls getValidInt() to accept an integer from 
the user and then it tests that input to make sure the integer is 
within the acceptable range. If it is not, it will ask the user again
to submit a valid input until the user does.
** Return value: Returns the submitted integer that is within the 
accepted range
*********************************************************************/
#include "getNumberBetween.hpp"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

int getNumberBetween(int low, int high)
{
    //Get an integer from the user
    int input = getValidInt();

    //Check that the integer is between low and high.
    if (input < low || input > high)
    {
        cout << "Please enter an integer between " << low << " and " << high << "." << endl;
        //Clear input stream
        cin.clear();
        input = getNumberBetween(low, high);
    }

    return input;
}

int getValidInt()
{
    //Input validation code and cin stream resetting adapted from https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
    //Accessed 1 Oct., 2019

    int input;
    float rawInput;
    cin >> rawInput;

    //Check that the inputted value is a number. If it isn't, ask the user for input again.
    if (!(cin))
    {
        cout << "Please enter an integer." << endl;
        //Clear input stream
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    //Check to make sure a decimal value hasn't been entered. If it isn't, ask the user for input again. This also checks that the max/min value of an int hasn't been exceeded
    //Will not reject an input that ends in ".0".
    input = rawInput; //value of "input" will be the floor of "rawInput".

    if (!(rawInput - input == 0))
    {
        cout << "Please enter an integer between -2147483648 and 2147483647.." << endl;

        //Clear input stream
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    return input;
}