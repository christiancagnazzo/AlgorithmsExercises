#pragma once

typedef struct _Couple {
  int key;
  int value;
} Couple;

void ArrayLib_quick_sort_int(Couple * array, int first_index, int last_index);

int ArrayLib_binary_search_value(Couple * array, int key, int first_index, int last_index);