#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode* prev;
    ListNode()
        : next(nullptr), prev(nullptr) {
        if constexpr (std::is_same_v<T, int>) {
            val = -1;
        } else if constexpr (std::is_same_v<T, std::string>) {
            val = "null";
        } else {
            val = T();   // class default constructor
        }
    }
    ListNode(T x)
        : val(x), next(nullptr), prev(nullptr) {}
    ListNode(T x, ListNode* next, ListNode* prev)
        : val(x), next(next), prev(prev) {}
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const ListNode<T>* head) {
    while (head) {
        os << head->val << " -> ";
        head = head->next;
    }
    os << "nullptr";
    return os;
}

// build a linkedlist from vector of T
template <typename T>
inline ListNode<T>* build_linkedlist(const std::vector<T>& nodes) {
    ListNode<T>* head = new ListNode<T>;
    ListNode<T>* p = head;
    for (auto x : nodes) {
        ListNode<T>* node = new ListNode<T>(x);
        p->next = node;
        p = p->next;
    }
    p->next = nullptr;
    return head->next;
}

#endif /* !LINKED_LIST_HPP */
