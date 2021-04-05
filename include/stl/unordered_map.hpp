#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include "pair.hpp"
#include <iostream>
#include <unordered_map>

template <typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<U, V>& m) {
    for (const auto& p : m) os << p << " ";
    return os;
}

#endif /* !UNORDERED_MAP_HPP */
