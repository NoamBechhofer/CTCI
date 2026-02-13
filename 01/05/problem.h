#ifndef PROBLEM_01_05_H
#define PROBLEM_01_05_H

#include <stdbool.h>
/**
 * @brief Problem 1.5 One Away
 *
 * There are three types of edits that can be performed on strings: insert a
 * character, remove a character, or replace a character. Given two strings,
 * write a function to check if they are one edit (or zero edits) away.
 */
bool
one_away(char const *const str1, char const *const str2);

#endif // PROBLEM_01_05_H