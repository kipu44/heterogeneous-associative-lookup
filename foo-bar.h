
#ifndef __FOO_BAR_H__
#define __FOO_BAR_H__

#include "counter.h"
#include "indent.h"

#include <iostream>
#include <string>

struct Foo
{
    Foo()                                   { std::cout << +i << "Foo() "  << a << " default-constructed" << "\n";                                      ++created.i; }
    ~Foo()                                  { std::cout << -i << "~Foo() " << a << (s.empty() ? "" : " ") << s << "\n";                         s = "destroyed"; }
    Foo(Foo && foo) noexcept : a(foo.a + 1) { std::cout << +i << "Foo() "  << a << " move-constructed from " << foo << "\n"; foo.s = "moved"; ++move.i; ++created.i; }
    Foo(const Foo & foo)     : a(foo.a + 1) { std::cout << +i << "Foo() "  << a << " copy-constructed from " << foo << "\n";                  ++copy.i; ++created.i; }

    Foo & operator=(Foo && foo) noexcept { (void)foo; return *this; }
    Foo & operator=(const Foo &  foo)    { (void)foo; return *this; }

    const int a = n();
    std::string s;
    Indent i;

    static Counter move;
    static Counter copy;
    static Counter created;
    static Counter stats;

    friend std::ostream & operator<<(std::ostream & stream, const Foo & foo);
};

struct Bar
{
    Bar(Foo && foo) noexcept : f(std::move(foo))   { std::cout << +i << "Bar(Foo && foo) " << f.a << "\n";      f.s = "inside Bar"; ++created.i; }
    Bar(const Foo & foo) : f(foo)                  { std::cout << +i << "Bar(const Foo & foo) " << f.a << "\n"; f.s = "inside Bar"; ++created.i; }
    ~Bar()                                         { std::cout << -i << "~Bar() " << f.a << "\n"; }
    Bar(Bar && bar) noexcept : f(std::move(bar.f)) { std::cout << +i << "Bar(Bar && bar) " << f.a << "\n";      ++move.i;           ++created.i; }
    Bar(const Bar & bar)     : f(bar.f)            { std::cout << +i << "Bar(const Bar & bar) " << f.a << "\n"; ++copy.i;           ++created.i; }

    Foo f;
    Indent i;

    static Counter move;
    static Counter copy;
    static Counter created;
    static Counter stats;
};

#endif
