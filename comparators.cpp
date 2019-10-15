
#include "comparators.h"

bool operator<(const Foo & foo1, const Foo & foo2)
{
    return foo1.a / 10 < foo2.a / 10;
}

bool operator<(const Foo & foo1, const Bar & bar2)
{
    return foo1 < bar2.f;
}

bool operator<(const Bar & bar1, const Foo & foo2)
{
    return bar1.f < foo2;
}

bool operator<(const Bar & bar1, const Bar & bar2)
{
    return bar1.f < bar2.f;
}
