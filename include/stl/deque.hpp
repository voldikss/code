#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <deque>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::deque<T>& dq) {
    int size = dq.size();
    while (size > 0) {
        os << dq.front() << " ";
        dq.push_back(dq.front());
        dq.pop_front();
        size--;
    }
    return os;
}

#endif /* !DEQUE_HPP */
