#include "sorting_lib.h"

static int partition(void ** array, SortingLibCmp compare, int first, int last){
  int i = first+1;
  int j = last;
  while (i<=j){
    if (compare(array[i],array[first]) <= 0)
      i++;
    else if (compare(array[j],array[first]) > 0)
      j--;
      else {
        void * temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
      }
  }
  void * temp = array[j];
  array[j] = array[first];
  array[first] = temp;
  return j;
}

void Sorting_Lib_quick_sort(void ** array, SortingLibCmp compare, int first_index, int last_index){
  if (last_index > 0){
    int p = partition(array, compare, first_index, last_index);
    if (p > 1)
      Sorting_Lib_quick_sort(array, compare, 0, p-1);
    if (p < last_index-1)
      Sorting_Lib_quick_sort(array, compare, p+1, last_index);
  }
}

void Sorting_Lib_insertion_sort(void ** array, SortingLibCmp compare, int num_elements){
  int i,j;
  void *temp;

  for (i = 1; i < num_elements; i++){ 
    j = i;
    while (j>0 && compare(array[j],array[j-1]) < 0){
      temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;            
      j--;
    }
  }
}





