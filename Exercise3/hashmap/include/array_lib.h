#pragma once

typedef struct _Couple {
  int key;
  int value;
} Couple;


/* Order an array using the quick sort algorithm */
void ArrayLib_quick_sort_int(Couple * array, int first_index, int last_index);

/* Binary search for a value within an array */
int ArrayLib_binary_search_value(Couple * array, int key, int first_index, int last_index);
