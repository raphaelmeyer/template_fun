#pragma once

#include <tfun/list.h>

template<typename> struct quicksort_;

template<>
struct quicksort_<list<>>
{
  using result = list<>;
};

template<typename Xs>
using quicksort = typename quicksort_<Xs>::result;
