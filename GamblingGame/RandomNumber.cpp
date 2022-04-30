#include "RandomNumber.h"
#include <cstdlib>

int RandomNumber::GenerateBetween(int min, int max)
{
    return min + (rand() % (max - min + 1));
}
