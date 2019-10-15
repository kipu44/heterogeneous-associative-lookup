
#include "foo-bar.h"

template <typename T>
void ignore(T /*t*/)
{
}

template <typename T>
void g(T && foo)
{
    auto b = foo;
    ignore(b);
    const auto c = foo;
    ignore(c);
    auto & d = foo;
    ignore(d);
    const auto & e = foo;
    ignore(e);
    auto * g = &foo;
    ignore(g);
    const auto * h = &foo;
    ignore(h);
}

auto foo()
{
    return Foo();
}

const auto & cfoo()
{
    static const Foo kFoo;
    return kFoo;
}

int main()
{
    Foo f1;
    const Foo f2;

    /*       Foo &  */ g(f1);
    /*       Foo && */ g(foo());
    /*       Foo && */ g(Foo());
    /*       Foo && */ g(std::move(f1));
    /*       Foo && */ g(std::move(foo()));
    /*       Foo && */ g(std::move(Foo()));
    /* const Foo &  */ g(cfoo());
    /* const Foo &  */ g(f2);
    /* const Foo && */ g(std::move(cfoo()));
    /* const Foo && */ g(std::move(f2));

    return 0;
}
