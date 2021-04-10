#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

namespace sort {

template <typename T>
void shell_sort(T arr[], int size) {
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = i; j < size; j++) {
            T tmp = arr[j];
            int k;
            for (k = j; k >= i && arr[k - i] > tmp; k -= i) {
                arr[k] = arr[k - i];
            }
            arr[k] = tmp;
        }
    }
}

}   // namespace sort

#endif /* !SHELL_SORT_HPP */
