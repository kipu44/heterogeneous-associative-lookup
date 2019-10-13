
#include "foo-bar.h"
#include <iostream>

using std::cout;

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
    {
        Foo f1;
        const Foo f2;

        /* (g)       Foo &  (f)       Foo &  */ g(f1);
        /* (g)       Foo && (f)       Foo &  */ g(foo());
        /* (g)       Foo && (f)       Foo &  */ g(Foo());
        /* (g)       Foo && (f)       Foo &  */ g(std::move(f1));
        /* (g)       Foo && (f)       Foo &  */ g(std::move(foo()));
        /* (g)       Foo && (f)       Foo &  */ g(std::move(Foo()));
        /* (g) const Foo &  (f) const Foo &  */ g(cfoo());
        /* (g) const Foo &  (f) const Foo &  */ g(f2);
        /* (g) const Foo && (f) const Foo &  */ g(std::move(cfoo()));
        /* (g) const Foo && (f) const Foo &  */ g(std::move(f2));
    }
    return 0;
}
