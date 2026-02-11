#ifndef PRINTF_DEBUG_H
#define PRINTF_DEBUG_H

#ifdef DEBUG
#include <stdio.h>
#define printf_debug(...) printf(__VA_ARGS__)
#else
#define printf_debug(...)
#endif

#endif