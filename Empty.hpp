#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Space.hpp"

class Empty : public Space
{
private:
public:
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    ~Empty();
    void interact(Inventory*);
};
#endif