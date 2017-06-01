#pragma once

#include <tfun/concat.h>
#include <tfun/list.h>

template <template <int> class, typename> struct map_;

template <template <int> class Function> struct map_<Function, list<>> {
  using result = list<>;
};

template <template <int> class Function, int X, int... Xs>
struct map_<Function, list<X, Xs...>> {
  using result = concat<list<Function<X>::result>,
                        typename map_<Function, list<Xs...>>::result>;
};

template <template <int> class Function, typename Xs>
using map = typename map_<Function, Xs>::result;
