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

void SortingLib_quick_sort(void ** array, SortingLibCmp compare, int first_index, int last_index){
  if (last_index - first_index > 0){
    int p = partition(array, compare, first_index, last_index);
    if (p > 1)
      SortingLib_quick_sort(array, compare, first_index, p-1);
    if (p < last_index-1)
      SortingLib_quick_sort(array, compare, p+1, last_index);
  }
}

void SortingLib_insertion_sort(void ** array, SortingLibCmp compare, int num_elements){
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

void SortingLib_three_way_quicksort(void ** array, SortingLibCmp compare, int first_index, int last_index) {
  if (last_index > first_index){
    void * temp;
    int middle_left_index = first_index;
    int middle_right_index = last_index;
    void * v = array[first_index];
    int i = first_index+1;

    while (i <= middle_right_index) {
      int cmp = compare(array[i],v);
      if (cmp < 0){
        temp = array[middle_left_index];
        array[middle_left_index] = array[i];
        array[i] = temp;  
        middle_left_index++;
        i++;
      }
      else if (cmp > 0){
        temp = array[i];
        array[i] = array[middle_right_index];
        array[middle_right_index] = temp;  
        middle_right_index--;
      }
      else
        i++;
    }

    SortingLib_three_way_quicksort(array, compare, first_index, middle_left_index-1);
    SortingLib_three_way_quicksort(array, compare, middle_right_index+1, last_index);
  }
}





