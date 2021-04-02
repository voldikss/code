#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (auto x : vec) os << x << " ";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec) {
    for (auto& x : vec) os << x << std::endl;
    return os;
}

#endif /* !VECTOR_HPP */
