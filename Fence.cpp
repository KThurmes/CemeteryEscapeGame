#include "Fence.hpp"
#include "Space.hpp"
#include <iostream>
using std::cout;

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