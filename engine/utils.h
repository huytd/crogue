#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool
is_between(int val, int min, int max);

bool
is_within_map(int x, int y);

int
min(int a, int b);

int
max(int a, int b);

int
gen_number(int min, int max);

int
string_comparator(const void* a, const void* b);

void
sort_strings(const char* arr[], int n);

#endif
