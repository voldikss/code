#include "bubble_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"
#include <cassert>
#include <iostream>
#include <memory.h>

using namespace sort;

#define ARRLEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define PRINT_ARRAY(arr)                  \
    for (int i = 0; i < ARRLEN(arr); i++) \
        std::cout << arr[i] << " ";

int arr[] = {20, 6, 16, 18, 1, 20, 18, 2, 3, 5};

void test_bubble_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    bubble_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_heap_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    heap_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_insertion_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    insertion_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_merge_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    merge_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));

    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    __merge(arr, 0, 3, 7);
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_merge_sort_down_to_up() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    merge_sort_down_to_up(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_selection_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    selection_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_quick_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    quick_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

void test_shell_sort() {
    int aux[ARRLEN(arr)];
    memcpy(aux, arr, sizeof(arr));
    shell_sort(arr, ARRLEN(arr));
    assert(is_sorted(arr, ARRLEN(arr)));
}

int main(int argc, char** argv) {
    test_bubble_sort();
    test_heap_sort();
    test_insertion_sort();
    test_merge_sort();
    test_merge_sort_down_to_up();
    test_quick_sort();
    test_selection_sort();
    test_shell_sort();
    return 0;
}
