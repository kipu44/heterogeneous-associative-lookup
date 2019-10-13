
#include "foo-bar.h"
#include "raii.h"
#include <iostream>
#include <map>

using std::cout;

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

template <typename M, typename T>
void find(M && map, T && t)
{
    const auto i = std::forward<M>(map).find(std::forward<T>(t));
    cout << (i == std::forward<M>(map).end() ? 0 : i->second) << "\n";
}

int main()
{
    Raii r1(11);

    const Foo f1;
    const Foo f2;
    const Foo f3;
    {
        const std::map<Bar, int> map =
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
    }
    return 0;
}
