#include "problem.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

static inline char
max(const char a, const char b)
{
    return a > b ? a : b;
}

static inline void
swap(char *const str, const size_t i, const size_t j)
{
    if (i == j)
        return;
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

static inline size_t
leftChild(const size_t i)
{
    return 2 * i + 1;
}

static inline size_t
rightChild(const size_t i)
{
    return 2 * i + 2;
}

static inline size_t
parent(const size_t i)
{
    return (i - 1) / 2;
}

static void
heapify(char *const str, const size_t str_len, const size_t root_idx)
{
    if (root_idx >= str_len)
        return;

    char root = str[root_idx];

    size_t left_idx = leftChild(root_idx);
    if (left_idx >= str_len)
        return;
    char left = str[left_idx];

    size_t right_idx = rightChild(root_idx);
    if (right_idx >= str_len) {
        if (left > root)
            swap(str, root_idx, left_idx);
        return;
    }
    char right = str[right_idx];

    if (root >= max(left, right))
        return;
    size_t swap_idx = (left > right) ? left_idx : right_idx;
    swap(str, root_idx, swap_idx);
    heapify(str, str_len, swap_idx);
}

static void
buildHeap(char *const str, const size_t str_len)
{
    size_t last_non_leaf = parent(str_len - 1);
    for (size_t i = last_non_leaf; i < SIZE_MAX; i--) {
        heapify(str, str_len, i);
    }
}

static void
heapSort(char *const str, const size_t str_len)
{
    buildHeap(str, str_len);
    for (size_t i = str_len - 1; i > 0; i--) {
        swap(str, 0, i);
        heapify(str, i, 0);
    }
}

static void
inPlaceSort(char *const str, const size_t str_len)
{
    /* We could also use quicksort. I opted for heapSort to preserve big O
    guarantees but in the real world we should use quicksort. */
    heapSort(str, str_len);
}

bool
isUnique(char *const str, const size_t str_len)
{
    if (str_len < 2)
        return true;

    inPlaceSort(str, str_len);
    /* n.b. we don't iterate on the last index */
    for (size_t i = 0; i < str_len - 1; i++)
        if (str[i] == str[i + 1])
            return false;

    return true;
}