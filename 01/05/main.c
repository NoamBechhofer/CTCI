#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "problem.h"

typedef struct
{
    char const *str1;
    char const *str2;
    const bool expected;
} TestCase;

int
main(void)
{

    TestCase test_cases[] = {
        { "", "", true },         { "", " ", true },
        { "", "  ", false },      { "a", "a", true },
        { "a", "ba", true },      { "ab", "a", true },
        { "a", "b", true },       { "ab", "ab", true },
        { "cab", "ab", true },    { "ab", "acb", true },
        { "abc", "ab", true },    { "ab", "cab", true },
        { "cab", "ca", true },    { "cab", "cb", true },
        { "cab", "dab", true },   { "cdb", "cab", true },
        { "cab", "cad", true },   { "cab", "dad", false },
        { "pale", "ple", true },  { "pales", "pale", true },
        { "pale", "bale", true }, { "pale", "bake", false },
    };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(TestCase); i++) {
        TestCase tc = test_cases[i];
        printf(
            "Test %zu: one_away(\"%s\", \"%s\") = ", i + 1, tc.str1, tc.str2);
        const bool result = one_away(tc.str1, tc.str2);
        printf("%s ", result ? "true" : "false");
        fflush(stdout);
        assert(result == tc.expected);
        printf("passed\n");
    }
}