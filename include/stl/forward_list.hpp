#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <forward_list>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::forward_list<T>& l) {
    for (auto& i : l) os << i << " ";
    return os;
}

#endif /* !FORWARD_LIST_HPP */
