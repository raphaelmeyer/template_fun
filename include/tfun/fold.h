#pragma once

#include <tfun/list.h>

template <template <int, int> class, typename> struct fold_;

template <template <int, int> class Function> struct fold_<Function, list<>> {
  static constexpr int result = 0;
};

template <template <int, int> class Function, int X>
struct fold_<Function, list<X>> {
  static constexpr int result = X;
};

template <template <int, int> class Function, int X, int... Xs>
struct fold_<Function, list<X, Xs...>> {
  static constexpr int result =
      Function<X, fold_<Function, list<Xs...>>::result>::result;
};

template <template <int, int> class Function, typename Xs>
constexpr int fold = fold_<Function, Xs>::result;
