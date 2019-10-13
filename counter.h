
#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>
#include <string>

int n();

struct Counter
{
    template <typename T>
    Counter(T && s) noexcept : s(std::forward<T>(s)) { }
    ~Counter() { std::cout << s; if (s.back() != ':') std::cout << " " << i; std::cout << "\n"; }

    std::string s;
    int i = 0;
};

#endif
