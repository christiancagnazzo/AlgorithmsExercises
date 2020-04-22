#include "array_lib.h"

static int partition(Couple * array, int first, int last){
  int i = first+1;
  int j = last;
  while (i<=j){
    if (array[i].key <= array[first].key)
      i++;
    else if (array[j].key > array[first].key)
      j--;
      else {
        Couple temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
      }
  }
  Couple temp = array[j];
  array[j] = array[first];
  array[first] = temp;
  return j;
}


void ArrayLib_quick_sort_int(Couple * array, int first_index, int last_index){
  if (last_index - first_index > 0){
    int p = partition(array, first_index, last_index);
    if (p > 1)
      ArrayLib_quick_sort_int(array, first_index, p-1);
    if (p < last_index-1)
      ArrayLib_quick_sort_int(array, p+1, last_index);
  }
}


int ArrayLib_binary_search_value(Couple * array, int key, int first_index, int last_index){
  if (first_index > last_index)
    return -1;
  else {
    int m = (last_index+first_index)/2;
    if (key == array[m].key)
      return array[m].value;
    else if (key < array[m].key)
      return ArrayLib_binary_search_value(array,key,first_index,m-1);
    else 
      return ArrayLib_binary_search_value(array,key,m+1,last_index);
  }        
}