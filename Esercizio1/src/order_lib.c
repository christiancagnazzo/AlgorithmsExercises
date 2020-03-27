#include "order_lib.h"


void insertion_sort(void ** array, OrderLibCmp compare, int num_elements){
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



