
#ifndef __INDENT_H__
#define __INDENT_H__

#include <string>

struct Indent
{
    Indent() : s((i += n) - n) { }
    ~Indent() { i = s; }

    std::string operator-() const { return std::string(s + 0, ' '); }
    std::string operator+() const { return std::string(s + 1, ' '); }

    const int s;

    static int i;
    static int n;
};

#endif
