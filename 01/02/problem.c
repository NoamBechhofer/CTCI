#include <limits.h>
#include <stddef.h>
#include <string.h>

#include "problem.h"

#define CHARSET_SIZE (UCHAR_MAX + 1)

static size_t
slot(const char c)
{
    return (size_t)((unsigned char)c);
}

bool
isPermutation(const char *const s1, const char *const s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    if (len1 != len2)
        return false;

    size_t frequencies[CHARSET_SIZE] = { 0 };

    for (size_t i = 0; i < len1; i++) {
        const char c = s1[i];
        frequencies[slot(c)]++;
    }

    for (size_t i = 0; i < len2; i++) {
        const char c = s2[i];
        if (frequencies[slot(c)]-- == 0)
            return false;
    }
    return true;
}
