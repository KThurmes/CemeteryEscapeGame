#include "Fence.hpp"
#include "Space.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Fence::Fence()
{

    passable = false;
}
Fence::~Fence()
{
}
void Fence::printSpaceTop()
{
    cout << "   ";
}
void Fence::printSpaceMiddle()
{
    cout << "---";
}
void Fence::printSpaceBottom()
{
    cout << "   ";
}

void Fence::interact()
{
    cout << "This is a pretty solid-looking fence." << endl;
}