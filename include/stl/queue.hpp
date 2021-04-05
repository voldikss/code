#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::queue<T>& q) {
    int size = q.size();
    while (size > 0) {
        os << q.front() << " ";
        q.push(q.front());
        q.pop();
        size--;
    }
    return os;
}

#endif /* !QUEUE_HPP */
