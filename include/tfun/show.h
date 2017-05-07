#pragma once

#include <tfun/list.h>

#include <sstream>
#include <string>

template <typename> struct show_;

template <> struct show_<list<>> {
  static std::string string() { return ""; }
};

template <int X> struct show_<list<X>> {
  static std::string string() {
    std::stringstream stream;
    stream << X;
    return stream.str();
  }
};

template <int X, int... Xs> struct show_<list<X, Xs...>> {
  static std::string string() {
    std::stringstream stream;
    stream << X << ", " << show_<list<Xs...>>::string();
    return stream.str();
  }
};

template <typename Xs> struct show {
  static std::string string() {
    std::stringstream stream;
    stream << "[" << show_<Xs>::string() << "]";
    return stream.str();
  }
};