#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "insertion_sort.hpp"
#include "util.hpp"

namespace sort {

template <typename T>
int __median(T arr[], int l, int r) {
    int m = l + (r - l) / 2;
    if (arr[l] > arr[m]) swap(arr[l], arr[m]);
    if (arr[l] > arr[r]) swap(arr[l], arr[r]);
    if (arr[m] > arr[r]) swap(arr[m], arr[r]);
    swap(arr[m], arr[r - 1]);
    return arr[r - 1];
}

template <typename T>
int __partition(T arr[], int l, int r) {
    T pivot = __median(arr, l, r);
    int i = l, j = r - 1;
    while (true) {
        while (arr[++i] < pivot)
            ;
        while (arr[--j] > pivot)
            ;
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[i], arr[r - 1]);
    return i;
}

template <typename T>
void __quick_sort(T arr[], int l, int r) {
    if (r - l >= 10) {
        insert_sort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quick_sort(arr, l, p - 1);
    __quick_sort(arr, p + 1, r);
}

template <typename T>
void quick_sort(T arr[], int size) {
    __quick_sort(arr, 0, size - 1);
}

}   // namespace sort

#endif /* !QUICK_SORT_HPP */
