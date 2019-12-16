
#include "comparators.h"
#include "foo-bar.h"
#include "raii.h"
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using std::cout;

template <typename M, typename T>
void find(M && map, T t) // TODO: What benefit does the moving give in this context?
{
    const auto i = std::forward<M>(map).find(std::forward<T>(t));
    cout << (i == std::forward<M>(map).end() ? 0 : i->second) << "\n";
}

template<typename List, typename Separator>
auto join1(const List & list, const Separator & separator)
{
  return std::accumulate(
    ++list.begin(), list.end(), list.front(), [separator](const auto & sum, const auto & addend) {
      return sum + separator + addend;
    });
}

template<typename List, typename Separator>
auto join2(const List & list, const Separator & separator)
{
  return std::accumulate(
    ++list.begin(), list.end(), list.front(), [&separator](const auto & sum, const auto & addend) {
      return sum + separator + addend;
    });
}

auto operator+(const Bar & bar, const Foo & /*foo*/)
{
  return bar;
}

auto operator+(const Bar & bar1, const Bar & /*bar2*/)
{
  return bar1;
}

int main()
{
    // Raii r1(11);
    //
    // const Foo f1;
    // Foo f2;
    // const Foo f3;
    //
    // const std::map<Bar, int, std::less<>> map =
    // {
    //     {f1, 1},
    //     {f2, 2},
    //     {f3, 3},
    // };
    //
    // { Raii r2(22); }
    //
    // { Raii r(1); find(map, Bar(Foo())); }
    // { Raii r(2); find(map, Foo()); }
    // { Raii r(3); find(map, Bar(f2)); }
    // { Raii r(4); find(map, std::move(f2)); }

    const Foo foo1;
    const Foo foo2;
    const Foo foo3;
    const Foo foo4;
    const Foo foo5;
    const Foo foo6;
    const Bar bar1(foo1);
    const Bar bar2(foo2);
    const Bar bar3(foo3);
    const Bar bar4(foo4);
    const Bar bar5(foo5);
    const Bar bar6(foo6);
    { Raii r3(33); }
    cout << "copy\n";
    join1(std::vector<Bar>{bar1, bar2}, foo3);
    { Raii r4(44); }
    cout << "reference\n";
    join2(std::vector<Bar>{bar4, bar5}, foo6);

    return 0;
}

// O0
/*
copy
   Foo() 12 copy-constructed from 11
      Bar(const Bar & bar) 12
         Foo() 22 copy-constructed from 21
            Bar(const Bar & bar) 22
               Foo() 13 copy-constructed from 12
                  Bar(const Bar & bar) 13
                     Foo() 23 copy-constructed from 22
                        Bar(const Bar & bar) 23
                           Foo() 14 copy-constructed from 13
                              Bar(const Bar & bar) 14
                                 Foo() 31 copy-constructed from 30
                                    Foo() 15 copy-constructed from 14
                                       Bar(const Bar & bar) 15
                                          Foo() 16 copy-constructed from 15
                                             Bar(const Bar & bar) 16
                                      ~Bar() 15
                                   ~Foo() 15
                                            ~Bar() 16
                                         ~Foo() 16
                                          Foo() 17 move-constructed from 16
                                             Bar(Bar && bar) 17
                                ~Foo() 31
                                            ~Bar() 16
                                         ~Foo() 16 moved
                                            ~Bar() 17
                                         ~Foo() 17
                       ~Bar() 23
                    ~Foo() 23
                 ~Bar() 13
              ~Foo() 13
           ~Bar() 22
        ~Foo() 22
     ~Bar() 12
  ~Foo() 12

reference
   Foo() 42 copy-constructed from 41
      Bar(const Bar & bar) 42
         Foo() 52 copy-constructed from 51
            Bar(const Bar & bar) 52
               Foo() 43 copy-constructed from 42
                  Bar(const Bar & bar) 43
                     Foo() 53 copy-constructed from 52
                        Bar(const Bar & bar) 53
                           Foo() 44 copy-constructed from 43
                              Bar(const Bar & bar) 44
                                 Foo() 45 copy-constructed from 44
                                    Bar(const Bar & bar) 45
                                       Foo() 46 copy-constructed from 45
                                          Bar(const Bar & bar) 46
                                   ~Bar() 45
                                ~Foo() 45
                                         ~Bar() 46
                                      ~Foo() 46
                                       Foo() 47 move-constructed from 46
                                          Bar(Bar && bar) 47
                                         ~Bar() 46
                                      ~Foo() 46 moved
                                         ~Bar() 47
                                      ~Foo() 47
                       ~Bar() 53
                    ~Foo() 53
                 ~Bar() 43
              ~Foo() 43
           ~Bar() 52
        ~Foo() 52
     ~Bar() 42
  ~Foo() 42
*/

// O3
/*
copy
   Foo() 12 copy-constructed from 11
      Bar(const Bar & bar) 12
         Foo() 22 copy-constructed from 21
            Bar(const Bar & bar) 22
               Foo() 13 copy-constructed from 12
                  Bar(const Bar & bar) 13
                     Foo() 23 copy-constructed from 22
                        Bar(const Bar & bar) 23
                           Foo() 14 copy-constructed from 13
                              Bar(const Bar & bar) 14
                                 Foo() 31 copy-constructed from 30
                                    Foo() 15 copy-constructed from 14
                                       Bar(const Bar & bar) 15
                                          Foo() 16 copy-constructed from 15
                                             Bar(const Bar & bar) 16
                                      ~Bar() 15
                                   ~Foo() 15
                                            ~Bar() 16
                                         ~Foo() 16
                                          Foo() 17 move-constructed from 16
                                             Bar(Bar && bar) 17
                                ~Foo() 31
                                            ~Bar() 16
                                         ~Foo() 16 moved
                                            ~Bar() 17
                                         ~Foo() 17
                       ~Bar() 23
                    ~Foo() 23
                 ~Bar() 13
              ~Foo() 13
           ~Bar() 22
        ~Foo() 22
     ~Bar() 12
  ~Foo() 12

reference
   Foo() 42 copy-constructed from 41
      Bar(const Bar & bar) 42
         Foo() 52 copy-constructed from 51
            Bar(const Bar & bar) 52
               Foo() 43 copy-constructed from 42
                  Bar(const Bar & bar) 43
                     Foo() 53 copy-constructed from 52
                        Bar(const Bar & bar) 53
                           Foo() 44 copy-constructed from 43
                              Bar(const Bar & bar) 44
                                 Foo() 45 copy-constructed from 44
                                    Bar(const Bar & bar) 45
                                       Foo() 46 copy-constructed from 45
                                          Bar(const Bar & bar) 46
                                   ~Bar() 45
                                ~Foo() 45
                                         ~Bar() 46
                                      ~Foo() 46
                                       Foo() 47 move-constructed from 46
                                          Bar(Bar && bar) 47
                                         ~Bar() 46
                                      ~Foo() 46 moved
                                         ~Bar() 47
                                      ~Foo() 47
                       ~Bar() 53
                    ~Foo() 53
                 ~Bar() 43
              ~Foo() 43
           ~Bar() 52
        ~Foo() 52
     ~Bar() 42
  ~Foo() 42
*/
