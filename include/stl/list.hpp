#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l) {
    for (auto& i : l) os << i << " ";
    return os;
}

#endif /* !LIST_HPP */
