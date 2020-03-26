#pragma once
#include <memory.h>

typedef int (*OrderLibCmp)(void*, void*);

void Swap(void *arr, int i, int j, size_t size);

/*Sort the elements of an array using the insertion sort algorithm. 
  Parameters: array, number of elements of array, 
  size of an element of the array and comparison function.
*/
void InsertionSort(void * array, OrderLibCmp, int NumElements, size_t SizeElements);

void QuickSort(void * array, OrderLibCmp);
