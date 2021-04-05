#ifndef UNORDERED_SET_HPP
#define UNORDERED_SET_HPP

#include <iostream>
#include <unordered_set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    for (const auto& x : s) os << x << " ";
    return os;
}

#endif /* !UNORDERED_SET_HPP */
