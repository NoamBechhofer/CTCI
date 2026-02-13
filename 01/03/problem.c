#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "problem.h"

void
urlify(char *const str, const size_t trueLength)
{
    const size_t full_length = strlen(str);

    size_t right = full_length - 1;

    for (size_t left = trueLength - 1; left != SIZE_MAX; left--) {
        switch (str[left]) {
            case ' ':
                str[right--] = '0';
                str[right--] = '2';
                str[right--] = '%';
                break;
            default:
                str[right--] = str[left];
        }
    }
}