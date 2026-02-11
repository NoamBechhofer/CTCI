#include <stdio.h>
#include <assert.h>
#include "problem.h"

typedef struct
{
    char *str;
    size_t len;
    bool expected;
} TestCase;

int main(void)
{
    printf("Testing Is Unique\n\n");

    /* there is no constraint against sorting the strings, but the problem 
     * specifies no additional data structures so the sorting should be 
     * in-place. Therefore we need stack allocated strings for testing. Regular
     * string literals are stored in read-only memory (the data segment) and
     * cannot be modified, so we need to use character arrays to allow for
     * in-place sorting if needed. */
    char s0[] = "";
    char s1[] = "a";
    char s2[] = "abcde";
    char s3[] = "hello";
    char s4[] = "1234567890";
    char s5[] = "AaBbCc";
    char s6[] = "AaBbCcA";
    char s7[] = "!@#$%^&*()";
    char s8[] = "!@#$%^&*()!";

    TestCase test_cases[] = {
        {s0, 0, true},
        {s1, 1, true},
        {s2, 5, true},
        {s3, 5, false},
        {s4, 10, true},
        {s5, 6, true},
        {s6, 7, false},
        {s7, 10, true},
        {s8, 11, false}};

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(TestCase); i++)
    {
        TestCase tc = test_cases[i];
        bool result = isUnique(tc.str, tc.len);
        assert(result == tc.expected);
        printf("Test %zu passed: \"%s\" is %s\n", i + 1, tc.str, result ? "unique" : "not unique");
    }
}