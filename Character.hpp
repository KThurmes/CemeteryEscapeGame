#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Space.hpp"

class Character
{
protected:
    Space *location;
    string symbol;

public:

    string getSymbol();
    virtual ~Character(){};
    void setLocation(Space *);
};

#endif