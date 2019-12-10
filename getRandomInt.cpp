/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: getRandomInt chooses a random integer between 
lowerLimit and upperLimit (inclusive)
*********************************************************************/

#include "getRandomInt.hpp"
#include <cstdlib>
#include <ctime>

int getRandomInt(int lowerLimit, int upperLimit)
{
    int range = upperLimit - lowerLimit + 1;
    return ((rand() % range) + lowerLimit);
}