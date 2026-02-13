#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "problem.h"

typedef struct
{
    char const *input;
    const bool expected;
} TestCase;

int
main(void)
{

    TestCase test_cases[] = { { "", true },
                              { " ", true },
                              { "a ", true },
                              { " a", true },
                              { "a", true },
                              { "ab ", false },
                              { " ab", false },
                              { "ab", false },
                              { "ba ", false },
                              { " ba", false },
                              { "ba", false },
                              { "baa", true },
                              { "aba", true },
                              { "aab", true },
                              { " baa", true },
                              { " aba", true },
                              { " aab", true },
                              { "b aa", true },
                              { "a ba", true },
                              { "a ab", true },
                              { "ba a", true },
                              { "ab a", true },
                              { "aa b", true },
                              { "baa ", true },
                              { "aba ", true },
                              { "aab ", true },
                              { "abc", false },
                              { " a a b b  ", true },
                              { " a a b b c ", true },
                              { " a a d b b c ", false } };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(TestCase); i++) {
        TestCase tc = test_cases[i];
        printf("Test %zu: palindrome_permutation(\"%s\") = ", i + 1, tc.input);
        const bool result = palindrome_permutation(tc.input);
        printf("%s ", result ? "true" : "false");
        fflush(stdout);
        assert(result == tc.expected);
        printf("passed\n");
    }
}