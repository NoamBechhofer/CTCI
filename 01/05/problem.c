#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "problem.h"

static bool
check_added(char const *shorter, char const *longer, size_t shorter_len)
{
    bool found_mismatch = false;
    for (size_t i = 0, j = 0; i < shorter_len; i++, j++) {
        if (shorter[i] != longer[j]) {
            if (found_mismatch)
                return false;
            found_mismatch = true;
            j++;
            if (longer[j] != shorter[i])
                return false;
        }
    }
    return true;
}

static bool
check_replaced(char const *const str1,
               char const *const str2,
               const size_t str_len)
{
    bool found_replacement = false;

    for (size_t i = 0; i < str_len; i++) {
        if (str1[i] != str2[i]) {
            if (found_replacement)
                return false;
            found_replacement = true;
        }
    }

    return true;
}

bool
one_away(char const *const str1, char const *const str2)
{
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);

    int size_diff = len1 - len2;
    if (size_diff > 1 || size_diff < -1)
        return false;
    if (size_diff == 0)
        return check_replaced(str1, str2, (size_t)len1);
    if (size_diff == 1)
        return check_added(str2, str1, (size_t)len2);
    assert(size_diff == -1);
    return check_added(str1, str2, (size_t)len1);
}