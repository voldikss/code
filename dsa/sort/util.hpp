#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>

namespace sort {

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void swap(T* pa, T* pb) {
    T tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

template <typename T>
void swap(T arr[], int i, int j) {
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

template <typename T>
bool is_sorted(T arr[], int size) {
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

}   // namespace sort

#endif /* !UTIL_HPP */
