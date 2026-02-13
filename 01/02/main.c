#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "problem.h"

typedef struct
{
    const char *s1;
    const char *s2;
    bool expected;
} TestCase;

int
main(void)
{

    TestCase test_cases[] = { { "", "", true },
                              { "a", "a", true },
                              { "a", "b", false },
                              { "abc", "bac", true },
                              { "aabbc", "bcaba", true },
                              { "abc", "ab", false },
                              { "abcde", "edcba", true },
                              { "hello", "oellh", true },
                              { "1234567890", "0987654321", true },
                              { "AaBbCc", "bBcCaA", true },
                              { "AaBbCcA", "aAbBcCA", true },
                              { "!@#$%^&*()", ")(*&^%$#@!", true },
                              { "!@#$%^&*()!", "!@#$%^&*()!", true },
                              { "abcde", "abcd", false },
                              { "hello", "helloo", false },
                              { "1234567890", "123456890", false },
                              { "AaBbCc", "AaBbCcc", false },
                              { "!@#$%^&*()", "!@#$%^&*() ", false } };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(TestCase); i++) {
        TestCase tc = test_cases[i];
        bool result = isPermutation(tc.s1, tc.s2);
        printf("Test %zu: \"%s\" and \"%s\" ", i + 1, tc.s1, tc.s2);
        assert(result == tc.expected);
        printf("passed: %s\n", result ? "permutations" : "not permutations");
    }
}