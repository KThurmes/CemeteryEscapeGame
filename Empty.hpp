#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Empty : public Space
{
private:
public:
    Empty();
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    ~Empty();
    void interact(Inventory *);
    void changeToDefaultSymbol();
};
#endif