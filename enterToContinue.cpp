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

    cin.get();
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}