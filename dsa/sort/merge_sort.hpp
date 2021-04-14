#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <memory.h>
#include <type_traits>

namespace sort {

/*
 * merge arr[l, m] and arr[m+1, r]
 */
template <typename T>
void __merge(T arr[], int l, int m, int r) {
    T* aux = new T[r - l + 1];
    if constexpr (std::is_trivial_v<T> && std::is_standard_layout_v<T>) {
        memcpy(aux, &arr[l], sizeof(T) * (r - l + 1));
    } else {
        for (int i = l; i <= r; i++) {
            aux[i - l] = arr[i];
        }
    }

    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++) {
        if (i > m)
            arr[k] = aux[j++ - l];
        else if (j > r)
            arr[k] = aux[i++ - l];
        else if (aux[i - l] < aux[j - l])
            arr[k] = aux[i++ - l];
        else
            arr[k] = aux[j++ - l];
    }
    delete[] aux;
}

template <typename T>
void __merge_sort(T arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    __merge_sort(arr, l, m);
    __merge_sort(arr, m + 1, r);
    __merge(arr, l, m, r);
}

template <typename T>
void merge_sort(T arr[], int size) {
    __merge_sort(arr, 0, size - 1);
}

template <typename T>
void merge_sort_down_to_up(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j += 2 * i) {
            if (arr[j + i - 1] > arr[j + i]) {
                __merge(arr, j, j + i - 1, std::min(j + 2 * i - 1, size - 1));
            }
        }
    }
}

}   // namespace sort

#endif /* !MERGE_SORT_HPP */
