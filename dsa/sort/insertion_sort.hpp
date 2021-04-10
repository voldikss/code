#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

namespace sort {

template <typename T>
void insertion_sort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T tmp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

}   // namespace sort

#endif /* !INSERTION_SORT_HPP */
