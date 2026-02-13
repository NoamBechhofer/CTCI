#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "problem.h"

typedef struct
{
    char *const input;
    const size_t true_length;
    const char *const expected;
} TestCase;

int
main(void)
{
    char s0_input[1] = "";
    char s1_input[2] = "a";
    char s2_input[4] = "   ";
    char s3_input[18] = "Mr John Smith    ";
    char s4_input[26] = "   leading spaces        ";
    char s5_input[27] = "trailing spaces           ";

    TestCase test_cases[] = {
        { s0_input, 0, "" },
        { s1_input, 1, "a" },
        { s2_input, 1, "%20" },
        { s3_input, 13, "Mr%20John%20Smith" },
        { s4_input, 17, "%20%20%20leading%20spaces" },
        { s5_input, 18, "trailing%20spaces%20%20%20" },
    };

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(TestCase); i++) {
        TestCase tc = test_cases[i];
        printf("Test %zu: urlify(\"%s\", %zu) = ",
               i + 1,
               tc.input,
               tc.true_length);
        urlify(tc.input, tc.true_length);
        printf("\"%s\" ", tc.input);
        fflush(stdout);
        assert(strcmp(tc.input, tc.expected) == 0);
        printf("passed\n");
    }
}