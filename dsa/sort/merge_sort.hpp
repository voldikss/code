#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <memory.h>
#include <type_traits>

namespace sort {

/*
 * merge arr[left, mid] and arr[mid+1, right]
 */
template <typename T>
void __merge(T arr[], int left, int mid, int right) {
    T* aux = new T[right - left + 1];
    if constexpr (std::is_trivial_v<T> && std::is_standard_layout_v<T>) {
        memcpy(aux, arr, sizeof(T) * (right - left + 1));
    } else {
        for (int i = left; i <= right; i++) {
            aux[i - left] = arr[i];
        }
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i > mid)
            arr[k] = aux[j++ - left];
        else if (j > right)
            arr[k] = aux[i++ - left];
        else if (aux[i - left] < aux[j - left])
            arr[k] = aux[i++ - left];
        else
            arr[k] = aux[j++ - left];
    }
    delete[] aux;
}

template <typename T>
void __merge_sort(T arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    __merge_sort(arr, 0, mid);
    __merge_sort(arr, mid + 1, right);
    __merge(arr, 0, mid, right);
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
