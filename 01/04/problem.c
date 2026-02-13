#include "problem.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

static inline uint32_t
init_bit_vec(void)
{
    return 0;
}

static inline uint32_t
toggle_bit(uint32_t const vec, const int idx)
{
    return vec ^ 1 << idx;
}

static inline uint32_t
toggle_corresponding_bit(uint32_t const vec, const char c)
{
    if (c >= 'A' && c <= 'Z')
        return toggle_bit(vec, c - 'A');
    if (c >= 'a' && c <= 'z')
        return toggle_bit(vec, c - 'a');
    return vec;
}

static inline bool
vec_has_at_most_one_bit_set(uint32_t const vec)
{
    return (vec & (vec - 1)) == 0;
}

bool
palindrome_permutation(char const *const str)
{
    uint32_t bit_vector = init_bit_vec();
    for (size_t i = 0; str[i] != '\0'; i++) {
        bit_vector = toggle_corresponding_bit(bit_vector, str[i]);
    }
    return vec_has_at_most_one_bit_set(bit_vector);
}