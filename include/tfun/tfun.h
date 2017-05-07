#pragma once

#include <sstream>
#include <string>

template <int...> struct list;

template <typename> struct show_;

template <>
struct show_<list<>>
{
  static std::string string() { return ""; }
};

template<int X>
struct show_<list<X>>
{
  static std::string string() {
    std::stringstream stream;
    stream << X;
    return stream.str();
  }
};

template <int X, int... Xs>
struct show_<list<X, Xs...>>
{
  static std::string string() {
    std::stringstream stream;
    stream << X << ", " << show_<list<Xs...>>::string();
    return stream.str();
  }
};

template <typename Xs>
struct show
{
  static std::string string()
  {
    std::stringstream stream;
    stream << "[" << show_<Xs>::string() << "]";
    return stream.str();
  }
};

// ---------------------------------------------------------------------------

template <typename, typename> struct concat_;

template <int... Xs, int... Ys>
struct concat_<list<Xs...>, list<Ys...>>
{
  using result = list<Xs..., Ys...>;
};

template <typename Xs, typename Ys>
using concat = typename concat_<Xs, Ys>::result;

// ---------------------------------------------------------------------------

template <int A, int B>
struct lt
{
  static constexpr bool result = A < B;
};

// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------

/*
template<int ...>
struct quicksort;

template<int X>
struct quicksort<X>
{
  using result = X;
};

struct<int X, int ... Xs>
struct quicksort<X, Xs ...>
{
  using result = join<quicksort<filter<Xs, smaller<X>>>, X, quicksort<filter<Xs, bigger<X>>>>;
};
 */