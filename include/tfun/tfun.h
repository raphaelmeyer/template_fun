#pragma once

#include <sstream>
#include <string>

template<int ...>
struct show;

template<int X>
struct show<X>
{
  static std::string string() {
    std::stringstream stream;
    stream << X;
    return stream.str();
  }
};

template<int X, int ... Xs>
struct show<X, Xs ...>
{
  static std::string string() {
    std::stringstream stream;
    stream << X << " " << show<Xs ...>::string();
    return stream.str();
  }
};

template<int ...>
struct quicksort;
