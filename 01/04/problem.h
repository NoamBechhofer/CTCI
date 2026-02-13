#ifndef PROBLEM_01_04_H
#define PROBLEM_01_04_H

#include <stdbool.h>
/**
 * @brief Problem 1.4: Palindrome Permutation
 *
 * Given a string, write a function to check if it is a permutation of a
 * palindrome. A palindrome is a word or phrase that reads the same backwards as
 * forwards. A permutation is a rearrangement of letters. The palindrome does
 * not need to be limited to just dictionary words. You can ignore casing and
 * non-letter characters.
 *
 * @param str The input string
 * @return true if the input string is a permutation of a palindrome, false
 * otherwise
 */
bool
palindrome_permutation(char const *const str);

#endif // PROBLEM_01_04_H