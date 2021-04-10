#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "insertion_sort.hpp"
#include "util.hpp"

namespace sort {

template <typename T>
T __median(T arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    swap(arr[mid], arr[right - 1]);
    return arr[right - 1];
}

template <typename T>
void __quick_sort(T arr[], int left, int right) {
    int pivot = __median(arr, left, right);
    int i = left, j = right - 1;
    while (true) {
        while (arr[++i] < pivot)
            ;
        while (arr[++j] > pivot)
            ;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[right - 1]);
    __quick_sort(arr, left, i - 1);
    __quick_sort(arr, i, right);
}

template <typename T>
void quick_sort(T arr[], int size) {
    if (size <= 15) {
        insertion_sort(arr, size);
    } else {
        __quick_sort(arr, 0, size - 1);
    }
}

}   // namespace sort

#endif /* !QUICK_SORT_HPP */
