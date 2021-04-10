#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "util.hpp"

namespace sort {

template <typename T>
void __shift_down(T arr[], int size, int i) {
    T tmp = arr[i];
    while (2 * i + 1 < size) {
        int j = 2 * i + 1;
        if (j + 1 < size && arr[j + 1] > arr[j])
            j++;
        if (tmp >= arr[j])
            break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = tmp;
}

template <typename T>
void heap_sort(T arr[], int size) {
    // 最后一个元素的索引为 (size-1)，其父节点索引为 (size-1-1)/2 即 (size-2)/2
    // 这里是先构建了一个大顶堆
    for (int i = (size - 2) / 2; i >= 0; i--) {
        __shift_down(arr, size, i);
    }

    // 不断将最大的堆顶元素**从后往前**放入列表中
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shift_down(arr, i, 0);
    }
}

}   // namespace sort

#endif /* !HEAP_SORT_HPP */
