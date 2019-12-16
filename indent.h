
#ifndef __INDENT_H__
#define __INDENT_H__

#include <string>

struct Indent
{
    Indent() : s((i += n) - n) { }
    ~Indent() { i = s; }

    Indent & operator=(const Indent & other) = default;
    Indent & operator=(Indent && other) = default;

    auto operator-() const { return std::string(s + 0, ' '); }
    auto operator+() const { return std::string(s + 1, ' '); }

    int s;

    static int i;
    static int n;
};

#endif
