#pragma once

typedef int (*SortingLibCmp)(void*, void*);

/* Sort the elements of an array by the insertion sort algorithm. 
  Parameters: array of object pointer, pointer to a comparison function and number of elements.
  The comparison function compares two objects in the array. 
  The library assumes that the function returns a value less than 0 if the first 
  object is smaller than the first, returns 0 if they are equal
  and it returns a value larger than 0 if the first object is larger than the second.
*/
void SortingLib_insertion_sort(void ** array, SortingLibCmp, int num_elements);

/* Sort the elements of an array by the quick sort algorithm. 
  Parameters: array of object pointer, pointer to  a comparison function, starting and ending 
  index of the array to be sorted.
  The comparison function compares two objects in the array. 
  The library assumes that the function returns a value less than 0 if the first 
  object is smaller than the first, returns 0 if they are equal
  and it returns a value larger than 0 if the first object is larger than the second.
*/
void SortingLib_quick_sort(void ** array, SortingLibCmp, int first_index, int last_index);
