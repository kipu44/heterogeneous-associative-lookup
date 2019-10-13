
#include "counter.h"

int n()
{
    static int c = 0;
    return c += 10;
}
