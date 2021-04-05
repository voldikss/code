#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <iostream>
#include <map>

template <typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<U, V>& m) {
    for (const auto& p : m) os << p << " ";
    return os;
}

#endif /* !MAP_HPP */
