#pragma once

typedef int (*OrderLibCmp)(void*, void*);

/*Sort the elements of an array of pointer using the insertion sort algorithm. 
  Parameters: array of pointer, number of elements of array.
*/
void insertion_sort(void ** array, OrderLibCmp, int num_elements);

/*
*/
void quick_sort(void ** array, OrderLibCmp, int first_index, int last_index);
