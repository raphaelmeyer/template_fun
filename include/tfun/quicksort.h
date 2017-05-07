#pragma once

#include <tfun/concat.h>
#include <tfun/filter.h>
#include <tfun/list.h>

template <int A, int B> struct le { static constexpr bool result = A <= B; };
template <int A, int B> struct gt { static constexpr bool result = A > B; };

template <typename> struct quicksort_;

template <> struct quicksort_<list<>> { using result = list<>; };

template <int Pivot, int... Xs> struct quicksort_<list<Pivot, Xs...>> {
  template <int X> using le_than_pivot = le<X, Pivot>;
  template <int X> using gt_than_pivot = gt<X, Pivot>;

  using smaller = filter<le_than_pivot, list<Xs...>>;
  using bigger = filter<gt_than_pivot, list<Xs...>>;

  using result =
      concat<concat<typename quicksort_<smaller>::result, list<Pivot>>,
             typename quicksort_<bigger>::result>;
};

template <typename Xs> using quicksort = typename quicksort_<Xs>::result;
