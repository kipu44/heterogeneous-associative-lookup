
#include "foo-bar.h"
#include <iostream>

using std::cout;

// void f(Foo foo)          { cout << ", " << foo << ", f: " << "      Foo   "; }
   void f(Foo & foo)        { cout << ", " << foo << ", f: " << "      Foo & "; }
   void f(Foo && foo)       { cout << ", " << foo << ", f: " << "      Foo &&"; }
// void f(const Foo foo)    { cout << ", " << foo << ", f: " << "const Foo   "; }
   void f(const Foo & foo)  { cout << ", " << foo << ", f: " << "const Foo & "; }
   void f(const Foo && foo) { cout << ", " << foo << ", f: " << "const Foo &&"; }

#if 0
   template <typename T>
   void g(T && foo)
   {
       cout << "/* g: " << "T &&"; f(std::forward<T>(foo)); cout << "\n";
   }
#else
// void g(Foo foo)          { cout << "/* g: " << "      Foo   "; f(foo); cout << " */\n"; }
   void g(Foo & foo)        { cout << "/* g: " << "      Foo & "; f(foo); cout << " */\n"; }
   void g(Foo && foo)       { cout << "/* g: " << "      Foo &&"; f(foo); cout << " */\n"; }
// void g(const Foo foo)    { cout << "/* g: " << "const Foo   "; f(foo); cout << " */\n"; }
   void g(const Foo & foo)  { cout << "/* g: " << "const Foo & "; f(foo); cout << " */\n"; }
   void g(const Foo && foo) { cout << "/* g: " << "const Foo &&"; f(foo); cout << " */\n"; }
#endif

auto foo()
{
    return Foo();
}

const auto & cfoo()
{
    static const Foo kFoo; // 70
    return kFoo;
}

int main()
{
    {
        Foo f1; // 10
        const Foo f2; // 20

        /* g:       Foo & , 10, f:       Foo &  */ g(f1);
        /* g:       Foo &&, 30, f:       Foo &  */ g(foo());
        /* g:       Foo &&, 40, f:       Foo &  */ g(Foo());
        /* g:       Foo &&, 10, f:       Foo &  */ g(std::move(f1));
        /* g:       Foo &&, 50, f:       Foo &  */ g(std::move(foo()));
        /* g:       Foo &&, 60, f:       Foo &  */ g(std::move(Foo()));
        /* g: const Foo & , 70, f: const Foo &  */ g(cfoo());
        /* g: const Foo & , 20, f: const Foo &  */ g(f2);
        /* g: const Foo &&, 70, f: const Foo &  */ g(std::move(cfoo()));
        /* g: const Foo &&, 20, f: const Foo &  */ g(std::move(f2));
    }
    return 0;
}
