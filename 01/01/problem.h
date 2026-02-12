#ifndef PROBLEM_01_01_H
#define PROBLEM_01_01_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Problem 1.1: Is Unique
 *
 * Determine if a string has all unique characters.
 *
 * @param str The input string to check
 * @param str_len The length of the input string
 * @return true if all characters are unique, false otherwise
 */
bool
isUnique(char *const str, const size_t str_len);

#endif // PROBLEM_01_01_H