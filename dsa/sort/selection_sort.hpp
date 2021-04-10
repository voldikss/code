#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "util.hpp"

namespace sort {

template <typename T>
void selection_sort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minidx]) {
                minidx = j;
                break;
            }
        }
        sort::swap(arr[i], arr[minidx]);
    }
}

}   // namespace sort

#endif /* !SELECTION_SORT_HPP */
