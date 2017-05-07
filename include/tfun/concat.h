#pragma once

#include <tfun/list.h>

template <typename, typename> struct concat_;

template <int... Xs, int... Ys>
struct concat_<list<Xs...>, list<Ys...>>
{
  using result = list<Xs..., Ys...>;
};

template <typename Xs, typename Ys>
using concat = typename concat_<Xs, Ys>::result;

