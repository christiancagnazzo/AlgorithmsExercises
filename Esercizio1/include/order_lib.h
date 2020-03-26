#pragma once
#include <memory.h>

typedef int (*OrderLibCmp)(void*, void*);

void Swap(void *arr, int i, int j, size_t size);

void InsertionSort(void * array, OrderLibCmp, int NumElements, size_t SizeElements);

void QuickSort(void * array, OrderLibCmp);
