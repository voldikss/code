#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "util.hpp"

namespace sort {

template <typename T>
void bubble_sort(T arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        bool is_sorted = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted) break;
    }
}

}   // namespace sort

#endif /* !BUBBLE_SORT_HPP */
