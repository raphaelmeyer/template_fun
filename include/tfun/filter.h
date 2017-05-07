#pragma once

#include <tfun/list.h>
#include <tfun/concat.h>

template <template <int> class, typename> struct filter_;

template <template <int> class Predicate>
struct filter_<Predicate, list<>>
{
  using result = list<>;
};

template <template <int> class Predicate, int X, int... Xs>
struct filter_<Predicate, list<X, Xs...>>
{
using result = concat<
std::conditional_t<Predicate<X>::result, list<X>, list<>>,
typename filter_<Predicate, list<Xs...>>::result>;
};

template <template <int> class Predicate, typename Xs>
using filter = typename filter_<Predicate, Xs>::result;
