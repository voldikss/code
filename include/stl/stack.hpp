#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::stack<T>& st) {
    std::stack<T> bak;
    while (!st.empty()) {
        bak.push(st.top());
        st.pop();
    }
    while (!bak.empty()) {
        os << bak.top() << " ";
        st.push(bak.top());
        bak.pop();
    }
    return os;
}

#endif /* !STACK_HPP */
