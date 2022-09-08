#ifndef UTILS_H
#define UTILS_H

#include "rogue.h"
#include <stdio.h>
#include <string.h>

static bool
is_between(int val, int min, int max)
{
    return val >= min && val <= max;
}

static bool
is_within_map(int x, int y)
{
    return is_between(x, 0, MAP_WIDTH - 1) && is_between(y, 0, MAP_HEIGHT - 1);
}

static int
min(int a, int b)
{
    return a < b ? a : b;
}

static int
max(int a, int b)
{
    return a > b ? a : b;
}

static int
gen_number(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

static int
string_comparator(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

static void
sort_strings(const char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), string_comparator);
}

#endif
