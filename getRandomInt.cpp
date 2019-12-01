#include "getRandomInt.hpp"
#include <cstdlib>
#include <ctime>

int getRandomInt(int lowerLimit, int upperLimit)
{
    int range = upperLimit - lowerLimit + 1;
    return ((rand() % range) + lowerLimit);
}