
#include "comparators.h"
#include "foo-bar.h"
#include "raii.h"
#include <iostream>
#include <map>

using std::cout;

template <typename M, typename T>
void find(const M & map, const T & t)
{
    const auto i = map.find(t);
    cout << (i == map.end() ? 0 : i->second) << "\n";
}

int main()
{
    Raii r1(11);

    const Foo f1;
    const Foo f2;
    const Foo f3;

    const std::map<Bar, int, std::less<>> map =
    {
        {f1, 1},
        {f2, 2},
        {f3, 3},
    };

    { Raii r2(22); }

    { Raii r(1); find(map, Bar(Foo())); }
    { Raii r(2); find(map, Foo()); }
    { Raii r(3); find(map, Bar(f2)); }
    { Raii r(4); find(map, f2); }

    return 0;
}
