#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

template <typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<U, V>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

#endif /* !PAIR_HPP */
