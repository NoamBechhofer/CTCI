#ifndef PROBLEM_01_03_H
#define PROBLEM_01_03_H

#include <stddef.h>
/**
 * @brief Problem 1.3: URLify
 *
 * Write a method to replace all spaces in a string with '%20'. You may assume
 * that the string has sufficient space at the end to hold the additional
 * characters, and that you are given the "true" length of the string.
 *
 * @note the string is modified in place
 *
 * @param str The input string
 * @param trueLength The "true" length of the input string
 */
void
urlify(char *const str, const size_t trueLength);

#endif // PROBLEM_01_03_H