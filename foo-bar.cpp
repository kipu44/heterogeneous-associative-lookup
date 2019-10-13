
#include "foo-bar.h"

Counter Foo::move("move");
Counter Foo::copy("copy");
Counter Foo::created("created");
Counter Foo::stats("statistics for Foo:");

std::ostream & operator<<(std::ostream & stream, const Foo & foo)
{
    return stream << std::to_string(foo.a);
}

Counter Bar::move("move");
Counter Bar::copy("copy");
Counter Bar::created("created");
Counter Bar::stats("statistics for Bar:");
