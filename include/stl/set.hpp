#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    for (const auto& x : s) os << x << " ";
    return os;
}

#endif /* !SET_HPP */
