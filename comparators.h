
#ifndef __COMPARATORS_H__
#define __COMPARATORS_H__

#include "foo-bar.h"

bool operator<(const Foo & foo1, const Foo & foo2);

bool operator<(const Foo & foo1, const Bar & bar2);
bool operator<(const Bar & bar1, const Foo & foo2);

bool operator<(const Bar & bar1, const Bar & bar2);

#endif
